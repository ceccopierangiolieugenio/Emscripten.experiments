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

static void rec_inv_str(char *c){
	/* this is the end (Tam Tam Tam)*/
	if (0 == *c) return;
	/* go to the first non white char */
	while (' ' == *c || '\t' == *c) ++c;
	/* get the length of this word (we could be at the end of the string) */
	int len = 0;
	while (' ' != c[len] && '\t' != c[len] && 0 != c[len]) ++len;
	/* invert this word (could be improved) */
	int i = len>>1;
	for (;i;--i){ 
		char bk = c[i-1];
		c[i-1]=c[len-i]; 
		c[len-i]=bk; 
	}
	/* recurse from the end of this word */
	rec_inv_str(c+len);
}

/* Emscripten function exported */
char * invert_string(char *c){
	rec_inv_str(c);
	return c;
}

