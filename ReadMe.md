### help
```
$ python main.py
Help on module moonlight:

NAME
    moonlight - pybind11 class plugin

CLASSES
    pybind11_builtins.pybind11_object(builtins.object)
        light
        moonlight

    class light(pybind11_builtins.pybind11_object)
     |  Method resolution order:
     |      light
     |      pybind11_builtins.pybind11_object
     |      builtins.object
     |
     |  Methods defined here:
     |
     |  __init__(...)
     |      __init__(self: moonlight.light) -> None
     |
     |  capture(...)
     |
     |  click(...)
     |      click(self: moonlight.light, arg0: int, arg1: int, arg2: int) -> None
     |
     |  fetchLattice(...)
     |
     |  finPic(...)
     |
     |  finPicEx(...)
     |
     |  findBrightPoint(...)
     |
     |  findColor(...)
     |
     |  findStr(...)
     |
     |  findStrEx(...)
     |
     |  findStrFast(...)
     |
     |  findStrFastEx(...)
     |
     |  getPath(...)
     |      getPath(self: moonlight.light) -> str
     |
     |  goHome(...)
     |      goHome(self: moonlight.light) -> None
     |
     |  hold(...)
     |      hold(self: moonlight.light, arg0: int, arg1: int, arg2: int) -> None
     |
     |  idx(...)
     |      idx(self: moonlight.light) -> int
     |
     |  move(...)
     |      move(self: moonlight.light, arg0: int, arg1: int, arg2: int) -> None
     |
     |  ocr(...)
     |
     |  onClear(...)
     |      onClear(self: moonlight.light, arg0: int) -> None
     |
     |  release(...)
     |      release(self: moonlight.light, arg0: int, arg1: int, arg2: int) -> None
     |
     |  sendText(...)
     |      sendText(self: moonlight.light, arg0: str) -> None
     |
     |  sendTextEx(...)
     |      sendTextEx(self: moonlight.light, arg0: str) -> None
     |
     |  setAdbPath(...)
     |      setAdbPath(self: moonlight.light, arg0: str) -> None
     |
     |  setDict(...)
     |      setDict(self: moonlight.light, arg0: int, arg1: str, arg2: str) -> int
     |
     |  setPath(...)
     |      setPath(self: moonlight.light, arg0: str) -> int
     |
     |  status(...)
     |      status(self: moonlight.light) -> bool
     |
     |  uiAutoMator(...)
     |      uiAutoMator(self: moonlight.light) -> List[List[str]]
     |
     |  uiClickBounds(...)
     |      uiClickBounds(self: moonlight.light, arg0: str) -> bool
     |
     |  uiFind(...)
     |      uiFind(self: moonlight.light, arg0: str, arg1: int) -> List[List[str]]
     |
     |  uiGetBounds(...)
     |      uiGetBounds(self: moonlight.light, arg0: str, arg1: int) -> List[List[int]]
     |
     |  useDict(...)
     |      useDict(self: moonlight.light, arg0: int) -> int
     |
     |  ver(...)
     |      ver(self: moonlight.light) -> str
     |
     |  x(...)
     |      x(self: moonlight.light) -> int
     |
     |  y(...)
     |      y(self: moonlight.light) -> int
     |
     |  ----------------------------------------------------------------------
     |  Static methods inherited from pybind11_builtins.pybind11_object:
     |
     |  __new__(*args, **kwargs) from pybind11_builtins.pybind11_type
     |      Create and return a new object.  See help(type) for accurate signature.

    class moonlight(pybind11_builtins.pybind11_object)
     |  Method resolution order:
     |      moonlight
     |      pybind11_builtins.pybind11_object
     |      builtins.object
     |
     |  Methods defined here:
     |
     |  __init__(...)
     |      __init__(self: moonlight.moonlight) -> None
     |
     |  getLight(...)
     |      getLight(self: moonlight.moonlight, arg0: str) -> light
     |
     |  isRunning(...)
     |      isRunning(self: moonlight.moonlight) -> bool
     |
     |  loop(...)
     |      loop(self: moonlight.moonlight) -> None
     |
     |  setAdbPatch(...)
     |      setAdbPatch(self: moonlight.moonlight, arg0: str) -> None
     |
     |  ----------------------------------------------------------------------
     |  Static methods inherited from pybind11_builtins.pybind11_object:
     |
     |  __new__(*args, **kwargs) from pybind11_builtins.pybind11_type
     |      Create and return a new object.  See help(type) for accurate signature.

```