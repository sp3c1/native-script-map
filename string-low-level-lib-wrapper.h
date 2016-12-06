#ifndef STRINGLOWLEVELLIBWRAPPER_H
#define STRINGLOWLEVELLIBWRAPPER_H

#include <node.h>
#include <node_object_wrap.h>
#include "string-low-level-lib.h"

class stringLowLevelLibWrapper : public node::ObjectWrap {
  public:
    static void Init(v8::Local<v8::Object> exports);

  private:
    explicit stringLowLevelLibWrapper();
    ~stringLowLevelLibWrapper();

    static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void PlusOne(const v8::FunctionCallbackInfo<v8::Value>& args);
    static v8::Persistent<v8::Function> constructor;
    stringLowLevelLib  value_;
};

#endif