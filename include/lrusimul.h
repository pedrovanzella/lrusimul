#ifndef _LRUSIMUL_H_
#define _LRUSIMUL_H_

void memsize(int size);
void procsize(int id, int size);
void read_p(int page, int id);
void write_p(int page, int id);
void endproc(int id);

#endif /* _LRUSIMUL_H_ */
