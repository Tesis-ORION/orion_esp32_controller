namespace diffrobot {

    struct Hw
    {
        // Left encoder channel A pin
        static const unsigned int kLeftEncoderChannelAGpioPin{32}; // Motor 1 Enc A
        // Left encoder channel B pin
        static const unsigned int kLeftEncoderChannelBGpioPin{33}; // Motor 1 Enc B
    
        // Right encoder channel A pin
        static const unsigned int kRightEncoderChannelAGpioPin{34}; // Motor 2 Enc A
        // Right encoder channel B pin
        static const unsigned int kRightEncoderChannelBGpioPin{35}; // Motor 2 Enc B
    
        // Left motor driver backward pin
        static const unsigned int kLeftMotorBackwardGpioPin{19}; // IN1
        // Left motor driver fordward pin
        static const unsigned int kLeftMotorForwardGpioPin{18}; // IN2
    
        // Right motor driver backward pin
        static const unsigned int kRightMotorBackwardGpioPin{21}; // IN3
        // Right motor driver fordward pin
        static const unsigned int kRightMotorForwardGpioPin{22}; // IN4
    
        // Enable input for left motor pin
        static const unsigned int kLeftMotorEnableGpioPin{16}; // ENA
        // Enable input for right motor pin
        static const unsigned int kRightMotorEnableGpioPin{17}; // ENB
    };

}
