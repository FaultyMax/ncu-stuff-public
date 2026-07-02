
import contextlib


@contextlib.contextmanager
def html_body(nazwa_pliku):

    with open(nazwa_pliku, "w") as f:
        f.write("<html><body>\n")

        yield f

        f.write("\n</body></html>\n")


with html_body("index.html") as f:
    f.write("<h1>Hello</h1>")
