/* 
 * Copyright 2015 Eugenio Parodi <ceccopierangiolieugenio at googlemail>.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "AudioProc.hpp"
#include "glue.AudioProc.cpp"

AudioProc::AudioProc(){}

void AudioProc::invertSamples(void * s, int n){
	float * in_s = (float *)s;
	for (int i = n/2 ; i; --i){
		float bk  = in_s[i-1];
		in_s[i-1] = in_s[n-i];
		in_s[n-i] = bk;
	}
}

