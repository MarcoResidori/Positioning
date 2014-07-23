/**************************************************************************
* @licence app begin@
*
* SPDX-License-Identifier: MPL-2.0
*
* \ingroup GNSSService
* \author Marco Residori <marco.residori@xse.de>
*
* \copyright Copyright (C) 2013, XS Embedded GmbH
* 
* \license
* This Source Code Form is subject to the terms of the
* Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
* this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
* @licence end@
**************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <unistd.h>

#include "gnss.h"
#include "gnss-ext.h"
#include "log.h"

DLT_DECLARE_CONTEXT(gCtx);

#define TEST_FAILED EXIT_FAILURE
#define TEST_PASSED EXIT_SUCCESS

static int testResult = TEST_PASSED;
static int cbSpatialSuccess = 0;

static void cbSpatial(const TGNSSSpatial spatial[], uint16_t numElements)
{
    int i;    
    if(spatial == NULL || numElements < 1)
    {
        LOG_ERROR_MSG(gCtx,"cbSpatial failed!");
        testResult = TEST_FAILED;
        return;
    }
    cbSpatialSuccess++;
    
    
}


bool checkMajorVersion(int expectedMajor)
{
    int major = -1;

    gnssGetVersion(&major, 0, 0);

    if(major != expectedMajor)
    {
        LOG_ERROR(gCtx,"Wrong API version: gnssGetVersion returned unexpected value %d != %d",
                  major, 
                  expectedMajor);

        testResult = TEST_FAILED;
        return false;
    }

    return true;
}

bool init()
{
    if(!checkMajorVersion(2))
    {
        return false;
    }

    if(!gnssInit())
    {
        return false;
    }

    if(!gnssExtendedInit())
    {
        return false;
    }

    return true;
}

int main()
{
    int i = 0;

    DLT_REGISTER_APP("GNSS", "GNSS-SERVICE-COMPLIANCE-TEST");
    DLT_REGISTER_CONTEXT(gCtx,"GCLT", "Global Context");
    
    LOG_INFO_MSG(gCtx,"Starting gnss-service-compliance-test...");

    if(init())
    {
        //register for GNSS
        gnssExtendedRegisterSpatialCallback(&cbSpatial);        

        //listen for events for about 10 seconds
        for(i = 0; i < 10; i++)
        {
            sleep(1);
        }

        //deregister
        gnssExtendedDeregisterSpatialCallback(&cbSpatial);        

        gnssExtendedDestroy();
        gnssDestroy();
    }
    
    //return if the test succeded or failed
    if(testResult == TEST_FAILED)
    { 
         LOG_INFO_MSG(gCtx,"TEST_FAILED");
         return EXIT_FAILURE;
    }

    LOG_INFO(gCtx,"TEST_PASSED with %d successful callbacks", cbSpatialSuccess);

    return EXIT_SUCCESS;
}
