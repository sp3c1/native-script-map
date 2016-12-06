#include <node.h>
#include "string-low-level-lib-wrapper.h"


using v8::Context;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::Persistent;
using v8::String;
using v8::Value;



Persistent<Function> stringLowLevelLibWrapper::constructor;

stringLowLevelLibWrapper::stringLowLevelLibWrapper() {
    //value_ = new stringLowLevelLib(); 
}

stringLowLevelLibWrapper::~stringLowLevelLibWrapper() {
}

void stringLowLevelLibWrapper::Init(Local<Object> exports) {
  Isolate* isolate = exports->GetIsolate();

  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
  tpl->SetClassName(String::NewFromUtf8(isolate, "stringLowLevelLibWrapper"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  NODE_SET_PROTOTYPE_METHOD(tpl, "plusOne", PlusOne);

  constructor.Reset(isolate, tpl->GetFunction());
  exports->Set(String::NewFromUtf8(isolate, "stringLowLevelLibWrapper"), tpl->GetFunction());
}

void stringLowLevelLibWrapper::New(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  if (args.IsConstructCall()) {
    // Invoked as constructor: `new stringLowLevelLibWrapper(...)`
    //double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
    stringLowLevelLibWrapper* obj = new stringLowLevelLibWrapper();
    obj->Wrap(args.This());
    args.GetReturnValue().Set(args.This());
  } else {
    // Invoked as plain function `stringLowLevelLibWrapper(...)`, turn into construct call.
    const int argc = 1;
    Local<Value> argv[argc] = { args[0] };
    Local<Context> context = isolate->GetCurrentContext();
    Local<Function> cons = Local<Function>::New(isolate, constructor);
    Local<Object> result =
        cons->NewInstance(context, argc, argv).ToLocalChecked();
    args.GetReturnValue().Set(result);
    //??? need to clear this?
  }
}

void stringLowLevelLibWrapper::PlusOne(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());

  args.GetReturnValue().Set(Number::New(isolate, obj->value_.size()));
}

