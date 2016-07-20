/*
    Copyright (c) 2016 Edouard M. Griffiths.  All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name of CM256 nor the names of its contributors may be
      used to endorse or promote products derived from this software without
      specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef UNIT_TEST_DATA_H_
#define UNIT_TEST_DATA_H_

#pragma pack(push, 1)
    struct Sample
    {
        uint16_t i;
        uint16_t q;
    };
    struct Header
    {
        uint16_t frameIndex;
        uint8_t  blockIndex;
        uint8_t  filler;
    };

    static const int udpSize = 512;
    static const int nbSamplesPerBlock = (512 - sizeof(Header)) / sizeof(Sample);
    static const int nbOriginalBlocks = 128;
    static const int nbRecoveryBlocks = 26;

    struct ProtectedBlock
    {
        Sample samples[nbSamplesPerBlock];
    };
    struct SuperBlock
    {
        Header         header;
        ProtectedBlock protectedBlock;
    };
#pragma pack(pop)


#endif /* UNIT_TEST_DATA_H_ */
