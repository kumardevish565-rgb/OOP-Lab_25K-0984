#pragma once

class SecurityDevice {
public:
    virtual void authenticate() = 0;
};

class BiometricScanner : public SecurityDevice {
    int attempts;
public:
    BiometricScanner();
    void authenticate() override;
};