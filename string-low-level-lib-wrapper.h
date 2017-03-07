#ifndef STRINGLOWLEVELLIBWRAPPER_H
#define STRINGLOWLEVELLIBWRAPPER_H

#include <node.h>
#include <node_object_wrap.h>
#include <nan.h>
#include "string-low-level-lib.h"

class stringLowLevelLibWrapper : public node::ObjectWrap {
  public:
    static void Init(v8::Local<v8::Object> exports);

  private:
    explicit stringLowLevelLibWrapper();
    ~stringLowLevelLibWrapper();

    static void New(const v8::FunctionCallbackInfo<v8::Value>& args);    
    static v8::Persistent<v8::Function> constructor;
    stringLowLevelLib  value_;
    

    static void add(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void append(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void regex(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void get(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void remove(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void chunk(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void size(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void sizeAt(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void hasIndex(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void clear(const v8::FunctionCallbackInfo<v8::Value>& args);
};

#endif
