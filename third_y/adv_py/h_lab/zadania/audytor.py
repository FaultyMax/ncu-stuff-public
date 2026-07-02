
import traceback
from datetime import datetime


class AudytorBledow:

    def __init__(self, sciezka, flaga):
        self.sciezka = sciezka
        self.tlumienie = flaga

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_value, tb):

        if exc_type:

            time = datetime.now().isoformat()
            error = "".join(
                traceback.format_exception(exc_type, exc_value, tb)
            )

            with open(self.sciezka, "a") as f:
                f.write(f"\n[{time}] {exc_type.__name__}\n")
                f.wrtie(error)
                f.write("\n")

            return self.tlumienie
            
        return False
