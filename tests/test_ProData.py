import unittest
import traceback

from ppap4lmp import Element, StaCustom, ProData, InvOMP

class TestProData(unittest.TestCase):

  def test_error(self):

    elems = [
      Element(StaCustom({"A": i, "B": i*i})) for i in range(1000)]
    pro = ProData(elems)
    pro.select("C")

    try:
      InvOMP(pro).execute()
    except SystemError:
      msg = traceback.format_exc()
      self.assertEqual(
        msg.split("\n")[0],
        "RuntimeError: ProData: Selected key(s) does not exist")

  def test_without_select(self):

    data = [{"A": i, "B": i*i} for i in range(1000)]
    elems = [Element(StaCustom(d)) for d in data]

    pro = ProData(elems)

    InvOMP(pro).execute()

    self.assertEqual(pro.get_results(), data)

    data = [
      [{"A": j, "B": i*j} for j in range(100)]
      for i in range(100)]
    elems = [Element(StaCustom(d)) for d in data]

    pro = ProData(elems)

    InvOMP(pro).execute()

    self.assertEqual(pro.get_results(), data)

  def test_with_select(self):

    data = [{"A": i, "B": i*i} for i in range(1000)]
    data2 = [{"A": i, "B": i*i, "C": i*i*i} for i in range(1000)]
    elems = [Element(StaCustom(
      {"A": d["A"], "B": d["B"], "C": d["A"] + d["B"]})) for d in data]

    pro = ProData(elems)
    pro.select("A", "B")

    InvOMP(pro).execute()

    self.assertEqual(pro.get_results(), data)

    data = [
      [{"A": j, "B": i*j} for j in range(100)]
      for i in range(100)]
    data2 = [
      [{"A": j, "B": i*j, "C": i+j} for j in range(100)]
      for i in range(100)]
    elems = [Element(StaCustom(d)) for d in data]

    pro = ProData(elems)
    pro.select("A", "B")

    InvOMP(pro).execute()

    self.assertEqual(pro.get_results(), data)