/**
* If not stated otherwise in this file or this component's LICENSE
* file the following copyright and licenses apply:
*
* Copyright 2020 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**/

#pragma once

#include "Module.h"
#include "WifiManagerDefines.h"

namespace WPEFramework {

    namespace Plugin {
        class WifiManagerInterface {
        public:
            virtual ~WifiManagerInterface() {}
            //Begin methods
            virtual uint32_t getQuirks(const JsonObject& parameters, JsonObject& response) const = 0;
            virtual uint32_t getCurrentState(const JsonObject& parameters, JsonObject& response) const = 0;
            virtual uint32_t startScan(const JsonObject& parameters, JsonObject& response) const = 0;
            virtual uint32_t stopScan(const JsonObject& parameters, JsonObject& response) = 0;
            virtual uint32_t getConnectedSSID(const JsonObject& parameters, JsonObject& response) const = 0;
            virtual uint32_t setEnabled(const JsonObject& parameters, JsonObject& response) = 0;
            virtual uint32_t connect(const JsonObject& parameters, JsonObject& response) = 0;
            virtual uint32_t disconnect(const JsonObject& parameters, JsonObject& response) = 0;
            virtual uint32_t initiateWPSPairing(const JsonObject& parameters, JsonObject& response) = 0;
            virtual uint32_t initiateWPSPairing2(const JsonObject& parameters, JsonObject& response) = 0;
            virtual uint32_t cancelWPSPairing(const JsonObject& parameters, JsonObject& response) = 0;
            virtual uint32_t saveSSID(const JsonObject& parameters, JsonObject& response) = 0;
            virtual uint32_t clearSSID(const JsonObject& parameters, JsonObject& response) = 0;
            virtual uint32_t getPairedSSID(const JsonObject& parameters, JsonObject& response) const = 0;
            virtual uint32_t getPairedSSIDInfo(const JsonObject& parameters, JsonObject& response) const = 0;
            virtual uint32_t isPaired(const JsonObject& parameters, JsonObject& response) const = 0;
            virtual uint32_t setSignalThresholdChangeEnabled(const JsonObject& parameters, JsonObject& response) = 0;
            virtual uint32_t isSignalThresholdChangeEnabled(const JsonObject& parameters, JsonObject& response) const = 0;
            virtual uint32_t getSupportedSecurityModes(const JsonObject& parameters, JsonObject& response) = 0;
            //End methods

            //Begin events
            virtual void onWIFIStateChanged(WifiState state, bool isLNF) = 0;
            virtual void onError(ErrorCode code) = 0;
            virtual void onSSIDsChanged() = 0;
            virtual void onWifiSignalThresholdChanged(float signalStrength, const std::string &strength) = 0;
            virtual void onAvailableSSIDs(JsonObject const& ssids) = 0;
            //End events
        };

    } // namespace Plugin
} // namespace WPEFramework
