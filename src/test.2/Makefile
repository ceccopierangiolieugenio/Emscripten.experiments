# Copyright 2015 Eugenio Parodi <ceccopierangiolieugenio at googlemail>.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

all:
	python2 ${EMSCRIPTEN}/tools/webidl_binder.py BaseMath.idl glue.BaseMath
	emcc BaseMath.cpp \
		-o ../../out.js/BaseMath.js \
		--post-js glue.BaseMath.js \
		-s TOTAL_MEMORY=33554432

clean:
	rm glue.* *.pkl *.out ../../out.js/BaseMath.js

