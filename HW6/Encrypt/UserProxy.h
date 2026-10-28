#pragma once
#include "User.h"
#include "EncryptStrategy.h"
#include "VerificationStrategy.h"

class UserProxy: public User
{
    EncryptStrategy* encStr;
    VerificationStrategy* verStr;
    RealUser* ruser;

public:
    UserProxy(RealUser* ruser, EncryptStrategy* encStr,VerificationStrategy* verStr):
        ruser(ruser), encStr(encStr), verStr(verStr) {}
    
    void sendMessage(std::string mes) override
    {
        std::string enc_mes = encStr->encode(mes);
        ruser->sendMessage(enc_mes);
        std::cout << verStr->verify(mes) << std::endl;
    }
    
};
