/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2019, Analog Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "local_eeprom.h"
// TO DO:
//#include "usb_eeprom.h"

#ifdef HAS_NETWORK
// TO DO:
//#include "ethernet_eeprom.h"
#endif

#include <aditof/eeprom_factory.h>

using namespace aditof;

std::unique_ptr<EepromInterface>
EepromFactory::buildEeprom(ConnectionType connection) {
    switch (connection) {
    case ConnectionType::USB: {
        // TO DO:
        //return std::unique_ptr<EepromInterface>(new UsbEeprom(data));
        return nullptr;
    }
    case ConnectionType::ETHERNET: {
#ifdef HAS_NETWORK
        // TO DO:
        //return std::unique_ptr<EepromInterface>(new EthernetEeprom(data));
        return nullptr;
#endif
        return nullptr;
    }
    case ConnectionType::LOCAL: {
        return std::unique_ptr<EepromInterface>(new LocalEeprom());
    }
    }

    return nullptr;
}
