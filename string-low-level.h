#ifndef STRINGLOWLEVEL_H
#define STRINGLOWLEVEL_H

#include <node.h>
#include "string-low-level-lib-wrapper.h"

using v8::Local;
using v8::Object;
using v8::Persistent;

void InitAll(Local<Object> exports) {
  stringLowLevelLibWrapper::Init(exports);
}

#endif
