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
using v8::Exception;
using v8::Boolean;

Nan::Persistent<v8::Function> stringLowLevelLibWrapper::constructor;

stringLowLevelLibWrapper::stringLowLevelLibWrapper() {
}

stringLowLevelLibWrapper::~stringLowLevelLibWrapper() {
}

void stringLowLevelLibWrapper::Init(Local<Object> exports) {
  Nan::HandleScope scope;

  // Prepare constructor template
  Local<FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("stringLowLevelLibWrapper").ToLocalChecked()); 
  tpl->InstanceTemplate()->SetInternalFieldCount(10);

  // Prototype
  Nan::SetPrototypeMethod(tpl, "add", add);
  Nan::SetPrototypeMethod(tpl, "append", append);
  Nan::SetPrototypeMethod(tpl, "regex", regex);
  Nan::SetPrototypeMethod(tpl, "get", get);
  Nan::SetPrototypeMethod(tpl, "remove", remove);
  Nan::SetPrototypeMethod(tpl, "chunk", chunk);
  Nan::SetPrototypeMethod(tpl, "size", size);
  Nan::SetPrototypeMethod(tpl, "sizeAt", sizeAt);
  Nan::SetPrototypeMethod(tpl, "hasIndex", hasIndex);
  Nan::SetPrototypeMethod(tpl, "clear", clear);

  constructor.Reset(tpl->GetFunction());
  exports->Set(Nan::New("stringLowLevelLibWrapper").ToLocalChecked(), tpl->GetFunction());
}

void stringLowLevelLibWrapper::New(const Nan::FunctionCallbackInfo<Value>& args) {
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
    v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
    args.GetReturnValue().Set(cons->NewInstance(argc, argv));
  }
}

void stringLowLevelLibWrapper::add(const Nan::FunctionCallbackInfo<Value>& args) {
  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());
  if (args.Length() != 1) {
    Nan::ThrowError("Wrong number of arguments");
    return;
  }

  try{
    if(!args[0]->IsString()){
      throw false;
    }

    args.GetReturnValue().Set(Nan::New(obj->value_.pushVector(args[0]->ToString())));
  }catch(...){
    Nan::ThrowError("Wrong number of arguments");
  }
}

void stringLowLevelLibWrapper::append(const Nan::FunctionCallbackInfo<Value>& args) {
  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());
  if (args.Length() != 2) {
     // Throw an Error that is passed back to JavaScript
    Nan::ThrowError("Wrong number of arguments");
    return;
  }

  try{
    if (!args[1]->IsString()){
      throw false;
    }

    obj->value_.appendVector((int)args[0]->IntegerValue(),args[1]->ToString());

  }catch (...){
    Nan::ThrowError("Can not append");
    return;
  }

}

void stringLowLevelLibWrapper::get(const Nan::FunctionCallbackInfo<Value>& args) {
  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());
  if (args.Length() != 1) {
    Nan::ThrowError("Wrong number of arguments");
    return;
  }

 int index = (int) args[0]->IntegerValue();

  try{
    args.GetReturnValue().Set(Nan::New<String>(obj->value_.lookUpVector(index)->c_str()).ToLocalChecked());
  }catch(...){
    Nan::ThrowError("Can not retrive element");
  }
}

void stringLowLevelLibWrapper::regex(const Nan::FunctionCallbackInfo<Value>& args) {
  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());

  if (args.Length() != 2) {
    Nan::ThrowError("Wrong number of arguments");
    return;
  }  

  bool regex=true;
  try{
    regex = obj->value_.regexVector((int) args[0]->IntegerValue(),*String::Utf8Value(args[1]->ToString()));
  }catch(...){
    Nan::ThrowError("Regex Exception");
    return; 
  }

  args.GetReturnValue().Set(Nan::New(regex));
}


void stringLowLevelLibWrapper::remove(const Nan::FunctionCallbackInfo<Value>& args) {
  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());

  if (args.Length() != 1) {
    Nan::ThrowError("Wrong number of arguments");
    return;
  }

  int removed = 0;

  try{
    removed = obj->value_.removeVector((int) args[0]->IntegerValue());
  }catch(...){
  }
  
  if(removed==0){
    Nan::ThrowError("Could not remove provided id");
    return;
  }
  return;
  
}

void stringLowLevelLibWrapper::chunk(const Nan::FunctionCallbackInfo<Value>& args) {
  if (args.Length() != 3) {
    Nan::ThrowError("Wrong number of arguments");
    return;
  }

  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());

  try{
      args.GetReturnValue().Set(
          Nan::New<String>(
              obj->value_.chunkData(
                  (int) args[0]->IntegerValue(),
                  (int) args[1]->IntegerValue(), 
                  (int)args[2]->IntegerValue()
                ).c_str()
              ).ToLocalChecked()
          );

  }catch(...){
     Nan::ThrowError("Chunking exception");
  }
  
}

void stringLowLevelLibWrapper::size(const Nan::FunctionCallbackInfo<Value>& args) {
  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());

  args.GetReturnValue().Set(Nan::New(obj->value_.size()));
}

void stringLowLevelLibWrapper::sizeAt(const Nan::FunctionCallbackInfo<Value>& args) {
  if (args.Length() != 1) {
      Nan::ThrowError("Wrong number of arguments");
      return;
  }

  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());

  try{
      args.GetReturnValue().Set(Nan::New(obj->value_.sizeAt((int) args[0]->IntegerValue())));
  }catch(...){
      Nan::ThrowError("Element does not exists"); 
  }
  
}

void stringLowLevelLibWrapper::hasIndex(const Nan::FunctionCallbackInfo<Value>& args) {
  if (args.Length() != 1) {
    Nan::ThrowError("Wrong number of arguments");
    return;
  }

  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());
  
  args.GetReturnValue().Set(Nan::New(obj->value_.hasAt((int) args[0]->IntegerValue())));
}

void stringLowLevelLibWrapper::clear(const Nan::FunctionCallbackInfo<Value>& args) {
  stringLowLevelLibWrapper* obj = ObjectWrap::Unwrap<stringLowLevelLibWrapper>(args.Holder());
  obj->value_.clear();
}