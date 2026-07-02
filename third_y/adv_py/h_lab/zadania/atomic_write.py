
import contextlib
import os


@contextlib.contextmanager
def bezpieczny_zapis(sciezka):
    
    sciezka_tmp = f"{sciezka}.tmp"

    f = open(sciezka_tmp, "w", encoding="utf-8")

    try:
        yield f
    except Exception as e:
        f.close()
        if os.path.exists(sciezka_tmp):
            os.remove(sciezka_tmp)
        raise e
    else:
        f.close()
        os.replace(sciezka_tmp, sciezka)


with bezpieczny_zapis("zapis.txt") as save:
    save.write("blabla\n")
