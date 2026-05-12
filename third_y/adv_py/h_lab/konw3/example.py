
'''

import random
import threading
import time


class Licznik:
  def __init__(self, start):
    self.dat = start
    self.lock = threading.Lock()

  def operacja(self):
    with self.lock:
      dane = self.dat
      time.sleep(random.random())
      self.dat = dane + 1
      print(f"Nowe dane", self.dat)



licznik = Licznik(1)
watki = [threading.Thread(
    target=licznik.operacja) 
         for _ in range(5)]

for w in watki:
    w.start()
for w in watki:
    w.join()

print(f"Ostatecznie: {licznik.dat}")

'''

import os
import contextlib


@contextlib.contextmanager
def switchdir_y(new_dir):
    cur_dir = os.getcwd()
    os.chdir(new_dir)

    yield os.getcwd()

    os.chdir(cur_dir)


with switchdir_y("/etc") as fst_dir, switchdir_y("udev") as sec_dir:
    print(f"{fst_dir} -> {sec_dir}")
