#ifndef STRINGLOWLEVELLIBWRAPPER_H
#define STRINGLOWLEVELLIBWRAPPER_H

#include <node.h>
#include <node_object_wrap.h>
#include <nan.h>
#include "string-low-level-lib.h"

class stringLowLevelLibWrapper : public  Nan::ObjectWrap {
  public:
    static void Init(v8::Local<v8::Object> exports);

  private:
    explicit stringLowLevelLibWrapper();
    ~stringLowLevelLibWrapper();

    static void New(const Nan::FunctionCallbackInfo<v8::Value>& args);    
    static Nan::Persistent<v8::Function> constructor;
    stringLowLevelLib  value_;
    

    static void add(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void append(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void regex(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void get(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void remove(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void chunk(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void size(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void sizeAt(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void hasIndex(const Nan::FunctionCallbackInfo<v8::Value>& args);
    static void clear(const Nan::FunctionCallbackInfo<v8::Value>& args);
};

#endif
