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

#include "BaseMath.hpp"
#include "glue.BaseMath.cpp"

BaseMath::BaseMath(){
	log.push_back("Constructor");
}

int BaseMath::sum(int a,int b){
	int res = a + b;
	log.push_back(__FUNCTION__);
	return a + b;
}

char * BaseMath::getFormattedLog(const char* prefix){
	std::string out = "";
	static char * ret = 0;
	for (std::vector<std::string>::iterator it = log.begin(); it != log.end(); ++it)
		out += prefix + *it + "\n";
	ret = new char(out.length()+1);
	memcpy(ret,out.c_str(),out.length()+1);
	return ret;
}

