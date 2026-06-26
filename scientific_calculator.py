import tkinter as tk
from tkinter import font as tkfont
import math
import re


# ─────────────────────────────────────────────
#  Calculation engine
# ─────────────────────────────────────────────
def evaluate(expression: str) -> str:
    """Safely evaluate a mathematical expression string."""
    # Replace display tokens with Python equivalents
    expr = expression
    expr = expr.replace("π", str(math.pi))
    expr = expr.replace("e", str(math.e))
    expr = expr.replace("^", "**")
    expr = expr.replace("×", "*")
    expr = expr.replace("÷", "/")

    # Trig / math function aliases  (work on degrees)
    def _sin(x):  return math.sin(math.radians(x))
    def _cos(x):  return math.cos(math.radians(x))
    def _tan(x):  return math.tan(math.radians(x))
    def _asin(x): return math.degrees(math.asin(x))
    def _acos(x): return math.degrees(math.acos(x))
    def _atan(x): return math.degrees(math.atan(x))

    safe_env = {
        "__builtins__": {},
        "sin": _sin, "cos": _cos, "tan": _tan,
        "asin": _asin, "acos": _acos, "atan": _atan,
        "log": math.log10,
        "ln": math.log,
        "sqrt": math.sqrt,
        "abs": abs,
        "factorial": math.factorial,
        "pi": math.pi,
        "e": math.e,
        "ceil": math.ceil,
        "floor": math.floor,
    }
    result = eval(expr, safe_env)  # noqa: S307  (educational tool)

    # Format: remove unnecessary trailing zeros
    if isinstance(result, float):
        if result == int(result) and abs(result) < 1e15:
            return str(int(result))
        return f"{result:.10g}"
    return str(result)


# ─────────────────────────────────────────────
#  Main application
# ─────────────────────────────────────────────
class ScientificCalculator(tk.Tk):
    # Colour palette
    BG         = "#1e1e2e"
    DISP_BG    = "#11111b"
    DISP_FG    = "#cdd6f4"
    DISP_SUB   = "#6c7086"
    BTN_NUM    = "#313244"
    BTN_OP     = "#45475a"
    BTN_SCI    = "#1e1e2e"
    BTN_ACCENT = "#89b4fa"   # blue  – equals
    BTN_CLR    = "#f38ba8"   # red   – clear / del
    BTN_MEM    = "#a6e3a1"   # green – memory
    BTN_FG     = "#cdd6f4"
    BTN_SCI_FG = "#89dceb"
    HOVER      = "#585b70"

    def __init__(self):
        super().__init__()
        self.title("Scientific Calculator")
        self.resizable(False, False)
        self.configure(bg=self.BG)

        self._expression = ""   # full expression being built
        self._history    = ""   # last full expression (shown above)
        self._memory     = 0.0
        self._just_eval  = False  # True right after '=' pressed

        self._build_fonts()
        self._build_display()
        self._build_buttons()
        self._bind_keyboard()

    # ── fonts ──────────────────────────────────
    def _build_fonts(self):
        self.f_disp   = tkfont.Font(family="Consolas", size=30, weight="bold")
        self.f_hist   = tkfont.Font(family="Consolas", size=13)
        self.f_btn    = tkfont.Font(family="Segoe UI",  size=13)
        self.f_btn_sm = tkfont.Font(family="Segoe UI",  size=11)

    # ── display panel ──────────────────────────
    def _build_display(self):
        frame = tk.Frame(self, bg=self.DISP_BG, pady=10, padx=14)
        frame.grid(row=0, column=0, sticky="nsew", padx=12, pady=(12, 4))

        self._hist_var = tk.StringVar(value="")
        self._expr_var = tk.StringVar(value="0")

        tk.Label(frame, textvariable=self._hist_var,
                 font=self.f_hist, bg=self.DISP_BG, fg=self.DISP_SUB,
                 anchor="e", width=34).pack(fill="x")

        tk.Label(frame, textvariable=self._expr_var,
                 font=self.f_disp, bg=self.DISP_BG, fg=self.DISP_FG,
                 anchor="e", width=34).pack(fill="x")

    # ── button grid ────────────────────────────
    def _build_buttons(self):
        frame = tk.Frame(self, bg=self.BG)
        frame.grid(row=1, column=0, padx=12, pady=(4, 12))

        # layout: (label, row, col, colspan, bg, fg, command)
        N  = self.BTN_NUM
        O  = self.BTN_OP
        S  = self.BTN_SCI
        A  = self.BTN_ACCENT
        C  = self.BTN_CLR
        M  = self.BTN_MEM
        BF = self.BTN_FG
        SF = self.BTN_SCI_FG

        buttons = [
            # ── row 0: memory & mode ──────────────────────────────────
            ("MC",    0, 0, 1, M, "#1e1e2e", self._mc),
            ("MR",    0, 1, 1, M, "#1e1e2e", self._mr),
            ("M+",    0, 2, 1, M, "#1e1e2e", self._mplus),
            ("M−",    0, 3, 1, M, "#1e1e2e", self._mminus),
            ("MS",    0, 4, 1, M, "#1e1e2e", self._ms),
            ("DEG",   0, 5, 1, S, SF,        None),           # label only

            # ── row 1: scientific ─────────────────────────────────────
            ("sin",   1, 0, 1, S, SF, lambda: self._fn("sin(")),
            ("cos",   1, 1, 1, S, SF, lambda: self._fn("cos(")),
            ("tan",   1, 2, 1, S, SF, lambda: self._fn("tan(")),
            ("asin",  1, 3, 1, S, SF, lambda: self._fn("asin(")),
            ("acos",  1, 4, 1, S, SF, lambda: self._fn("acos(")),
            ("atan",  1, 5, 1, S, SF, lambda: self._fn("atan(")),

            # ── row 2: scientific ─────────────────────────────────────
            ("x²",    2, 0, 1, S, SF, lambda: self._append("^2")),
            ("x³",    2, 1, 1, S, SF, lambda: self._append("^3")),
            ("xⁿ",    2, 2, 1, S, SF, lambda: self._append("^")),
            ("√",     2, 3, 1, S, SF, lambda: self._fn("sqrt(")),
            ("log",   2, 4, 1, S, SF, lambda: self._fn("log(")),
            ("ln",    2, 5, 1, S, SF, lambda: self._fn("ln(")),

            # ── row 3: scientific + clear ─────────────────────────────
            ("n!",    3, 0, 1, S, SF, lambda: self._append("!")),
            ("|x|",   3, 1, 1, S, SF, lambda: self._fn("abs(")),
            ("1/x",   3, 2, 1, S, SF, lambda: self._append("^-1")),
            ("π",     3, 3, 1, S, SF, lambda: self._append("π")),
            ("e",     3, 4, 1, S, SF, lambda: self._append("e")),
            ("AC",    3, 5, 1, C, "#1e1e2e", self._clear_all),

            # ── row 4: brackets + ops ─────────────────────────────────
            ("(",     4, 0, 1, O, BF, lambda: self._append("(")),
            (")",     4, 1, 1, O, BF, lambda: self._append(")")),
            ("%",     4, 2, 1, O, BF, lambda: self._append("%")),
            ("⌫",     4, 3, 1, C, "#1e1e2e", self._backspace),
            ("÷",     4, 4, 1, O, BF, lambda: self._append("÷")),
            ("×",     4, 5, 1, O, BF, lambda: self._append("×")),

            # ── rows 5-7: digits + ops ────────────────────────────────
            ("7",     5, 0, 1, N, BF, lambda: self._digit("7")),
            ("8",     5, 1, 1, N, BF, lambda: self._digit("8")),
            ("9",     5, 2, 1, N, BF, lambda: self._digit("9")),
            ("−",     5, 3, 1, O, BF, lambda: self._append("−")),
            ("ceil",  5, 4, 1, S, SF, lambda: self._fn("ceil(")),
            ("floor", 5, 5, 1, S, SF, lambda: self._fn("floor(")),

            ("4",     6, 0, 1, N, BF, lambda: self._digit("4")),
            ("5",     6, 1, 1, N, BF, lambda: self._digit("5")),
            ("6",     6, 2, 1, N, BF, lambda: self._digit("6")),
            ("+",     6, 3, 1, O, BF, lambda: self._append("+")),
            ("EXP",   6, 4, 2, S, SF, lambda: self._append("*10^")),

            ("1",     7, 0, 1, N, BF, lambda: self._digit("1")),
            ("2",     7, 1, 1, N, BF, lambda: self._digit("2")),
            ("3",     7, 2, 1, N, BF, lambda: self._digit("3")),
            ("=",     7, 3, 1, A, "#1e1e2e", self._equals),
            ("ANS",   7, 4, 2, O, BF, self._ans),

            # ── row 8: zero row ───────────────────────────────────────
            ("0",     8, 0, 2, N, BF, lambda: self._digit("0")),
            (".",     8, 2, 1, N, BF, lambda: self._append(".")),
            ("±",     8, 3, 1, O, BF, self._negate),
            ("C",     8, 4, 2, C, "#1e1e2e", self._clear_entry),
        ]

        for (text, row, col, span, bg, fg, cmd) in buttons:
            self._make_button(frame, text, row, col, span, bg, fg, cmd)

    def _make_button(self, parent, text, row, col, span, bg, fg, cmd):
        is_small = len(text) >= 4
        f = self.f_btn_sm if is_small else self.f_btn
        state = "normal" if cmd else "disabled"

        btn = tk.Button(
            parent,
            text=text,
            font=f,
            bg=bg, fg=fg,
            activebackground=self.HOVER,
            activeforeground=self.BTN_FG,
            bd=0, relief="flat",
            width=5 if span == 1 else 11,
            height=2,
            cursor="hand2",
            command=cmd,
            state=state,
        )
        btn.grid(row=row, column=col, columnspan=span,
                 padx=3, pady=3, sticky="nsew")

        # Hover effect
        btn.bind("<Enter>", lambda e, b=btn: b.config(bg=self.HOVER))
        btn.bind("<Leave>", lambda e, b=btn, c=bg: b.config(bg=c))

    # ── keyboard binding ───────────────────────
    def _bind_keyboard(self):
        mapping = {
            "<Return>":      self._equals,
            "<KP_Enter>":    self._equals,
            "<BackSpace>":   self._backspace,
            "<Delete>":      self._clear_all,
            "<Escape>":      self._clear_all,
        }
        for key, fn in mapping.items():
            self.bind(key, lambda e, f=fn: f())

        for ch in "0123456789.+-*/()%^":
            self.bind(ch, lambda e, c=ch: self._key_char(c))

    def _key_char(self, ch):
        char_map = {"*": "×", "/": "÷", "-": "−"}
        self._append(char_map.get(ch, ch))

    # ── state helpers ──────────────────────────
    def _update_display(self):
        text = self._expression if self._expression else "0"
        self._expr_var.set(text)

    def _append(self, token: str):
        # After '=' continue from result unless token is an operator
        if self._just_eval:
            operators = set("+-×÷^%")
            if token[0] not in operators and token not in ("^2", "^3", "^-1", "!"):
                self._expression = ""
            self._just_eval = False
        self._expression += token
        self._update_display()

    def _digit(self, d: str):
        self._append(d)

    def _fn(self, fn: str):
        self._just_eval = False
        self._expression += fn
        self._update_display()

    # ── button actions ─────────────────────────
    def _clear_all(self):
        self._expression = ""
        self._history    = ""
        self._just_eval  = False
        self._hist_var.set("")
        self._update_display()

    def _clear_entry(self):
        self._expression = ""
        self._just_eval  = False
        self._update_display()

    def _backspace(self):
        if self._just_eval:
            return
        self._expression = self._expression[:-1]
        self._update_display()

    def _negate(self):
        expr = self._expression
        if not expr:
            return
        # Wrap whole expression in negation
        self._expression = f"(-({expr}))"
        self._update_display()

    def _equals(self):
        if not self._expression:
            return
        raw = self._expression
        # Replace display minus with Python minus
        py_expr = raw.replace("−", "-").replace("!", " and True or math.factorial(int(")
        # Simple factorial fix: convert "n!" → "factorial(n)"
        py_expr = re.sub(r'(\d+)!', r'factorial(\1)', raw.replace("−", "-"))
        try:
            result = evaluate(py_expr)
            self._hist_var.set(raw + "  =")
            self._expression = result
            self._just_eval  = True
        except ZeroDivisionError:
            self._hist_var.set(raw)
            self._expression = "Error: ÷ by 0"
            self._just_eval  = False
        except Exception:
            self._hist_var.set(raw)
            self._expression = "Error"
            self._just_eval  = False
        self._update_display()

    def _ans(self):
        """Insert the last result."""
        if self._just_eval:
            pass   # expression already is the result
        elif self._history:
            pass
        # Re-use current display value as ANS
        ans = self._expression if self._just_eval else self._expression
        if ans and ans not in ("Error", "Error: ÷ by 0"):
            self._just_eval  = False
            self._expression = ans
            self._update_display()

    # ── memory ─────────────────────────────────
    def _current_value(self) -> float:
        try:
            return float(evaluate(self._expression.replace("−", "-")))
        except Exception:
            return 0.0

    def _mc(self):
        self._memory = 0.0

    def _mr(self):
        val = str(self._memory)
        if val.endswith(".0"):
            val = val[:-2]
        self._just_eval = False
        self._expression += val
        self._update_display()

    def _mplus(self):
        self._memory += self._current_value()

    def _mminus(self):
        self._memory -= self._current_value()

    def _ms(self):
        self._memory = self._current_value()


# ─────────────────────────────────────────────
if __name__ == "__main__":
    app = ScientificCalculator()
    app.mainloop()
