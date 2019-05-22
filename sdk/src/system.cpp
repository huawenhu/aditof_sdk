#include "system.h"
#include "camera.h"
#include "system_impl.h"

namespace aditof {

System::System() : m_impl(new SystemImpl) {}
System::~System() = default;
System::System(System &&) noexcept = default;
System &System::operator=(System &&) noexcept = default;

Status System::initialize() { return m_impl->initialize(); }

Status
System::getCameraList(std::vector<std::shared_ptr<Camera>> &cameraList) const {
    return m_impl->getCameraList(cameraList);
}

} // namespace aditof
