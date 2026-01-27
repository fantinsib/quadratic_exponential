#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <optional>
#include "types/path.hpp"
#include "types/state.hpp"

namespace py = pybind11; 

namespace qe::pybind {

void bind_types(py::module_& m) {
    py::class_<State>(m, "_State")
        .def(py::init<>())
        .def("_spot", &State::spot)
        .def("_vol", &State::vol);

    py::class_<Path>(m, "_Path")
        .def(py::init<>())
        .def("end_state", &Path::end_state, py::return_value_policy::reference_internal)
        .def("__len__", &Path::size)
        .def("len", &Path::size)
        .def("at", &Path::at,
            py::arg("i"), py::return_value_policy::reference_internal);
}

} // namespace qe::pybind
