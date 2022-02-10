#include <string>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "pybindmoon/moonlight.h"
#include "pybindmoon/light.h"
namespace py = pybind11;

PYBIND11_MODULE(moonlight, m)
{
    m.doc() = "pybind11 class plugin"; // optional module docstring

    py::class_<moonlight>(m, "moonlight")
        .def(py::init<>())
        .def("loop", &moonlight::loop)
        .def("isRunning", &moonlight::isRunning)
        .def("setAdbPatch", &moonlight::setAdbPatch)
        .def("getLight", &moonlight::getLight),
        "moonlight_Server";

    py::class_<light>(m, "light")
        .def(py::init<>())
        .def("status", &light::status)
        //control
        .def("hold", &light::hold)
        .def("move", &light::move)
        .def("release", &light::release)
        .def("click", &light::click)
        .def("sendText", &light::sendText)
        .def("sendTextEx", &light::sendTextEx)

        //ocr
        .def("setDict", &light::setDict)
        .def("useDict", &light::useDict)
        .def("ocr", &light::ocr)
        .def("findStr", &light::findStr)
        .def("findStrEx", &light::findStrEx)
        .def("findStrFast", &light::findStrFast)
        .def("findStrFastEx", &light::findStrFastEx)
        .def("fetchLattice", &light::fetchLattice)

        //pic
        .def("finPic", &light::finPic)
        .def("finPicEx", &light::finPicEx)
        .def("findBrightPoint", &light::findBrightPoint)
        .def("findColor", &light::findColor)
        .def("capture", &light::capture)

        //base
        .def("x", &light::x)
        .def("y", &light::y)
        .def("idx", &light::idx)
        .def("setPath", &light::setPath)
        .def("getPath", &light::getPath)

        //android-keyCode
        .def("key", &light::key)
        .def("goHome", &light::goHome)
        .def("onClear", &light::onClear)
        
        //uiAutoMator
        .def("setAdbPath", &light::setAdbPatch)
        .def("uiAutoMator", &light::uiAutoMator)
        .def("uiFind", &light::uiFind)
        .def("uiGetBounds", &light::uiGetBounds)
        .def("uiClickBounds", &light::uiClickBounds)

        .def("ver", &light::ver),
        "Control Android Object";
}