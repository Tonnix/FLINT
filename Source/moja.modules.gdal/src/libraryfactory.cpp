#include "moja/modules/gdal/libraryfactory.h"

#include "moja/modules/gdal/writevariablegeotiff.h"

#include <moja/flint/mojalibapi.h>

using moja::flint::DataRepositoryProviderRegistration;
using moja::flint::FlintDataFactoryRegistration;
using moja::flint::FlintDataRegistration;
using moja::flint::IFlintData;
using moja::flint::IModule;
using moja::flint::ITransform;
using moja::flint::ModuleRegistration;
using moja::flint::TransformRegistration;

namespace moja {
namespace modules {
namespace gdal {

extern "C" {

Poco::Mutex _fileHandlingMutexVarGeotiffWriter;

MOJA_LIB_API int getModuleRegistrations(ModuleRegistration* outModuleRegistrations) {
   int index = 0;
   outModuleRegistrations[index++] = ModuleRegistration{
       "WriteVariableGeotiff",
       []() -> flint::IModule* { return new WriteVariableGeotiff(_fileHandlingMutexVarGeotiffWriter); }};
   return index;
}

MOJA_LIB_API int getTransformRegistrations(TransformRegistration* outTransformRegistrations) {
   int index = 0;
   return index;
}

MOJA_LIB_API int getFlintDataRegistrations(FlintDataRegistration* outFlintDataRegistrations) {
   auto index = 0;
   return index;
}

MOJA_LIB_API int getFlintDataFactoryRegistrations(FlintDataFactoryRegistration* outFlintDataFactoryRegistrations) {
   auto index = 0;
   return index;
}

MOJA_LIB_API int getDataRepositoryProviderRegistrations(
    moja::flint::DataRepositoryProviderRegistration* outDataRepositoryProviderRegistration) {
   auto index = 0;
   return index;
}
}

}  // namespace gdal
}  // namespace modules
}  // namespace moja
