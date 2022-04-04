#include "rt_nonfinite.h"
#include "test.h"
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "test_types.h"
#include "test_terminate.h"
#include "test_emxAPI.h"
#include "test_initialize.h"
#include <iostream>
using namespace std;

static emxArray_real_T *argInit_1xUnbounded_real_T()
{
	static int iv0[2] = { 1, 2 };
	emxArray_real_T *result = emxCreateND_real_T(2, iv0);

	for (int idx1 = 0; idx1 < result->size[1]; idx1++) {
		result->data[result->size[0] * idx1] = 0.0;
	}

	return result;
}

int main(int, const char * const[])
{
	test_initialize();

	emxArray_creal_T *fp;
	emxArray_real_T *Id1;
	emxArray_real_T *Qd1;

	emxInitArray_creal_T(&fp, 2);
	int iv0[2] = { 1, 60 };
	emxArray_real_T *Id1 = emxCreateND_real_T(2, iv0);
	emxArray_real_T *Qd1 = emxCreateND_real_T(2, iv0);

	//假数据
	for (int idx1 = 0; idx1 < iv0[1]; idx1++) {
		Id1->data[Id1->size[0] * idx1] = 0.0;
		Qd1->data[Qd1->size[0] * idx1] = 0.0;
	}

	test(Id1, Qd1, fp);
	cout << fp->data[0].re << "+" << fp->data[0].im << "i" << endl;

	emxDestroyArray_creal_T(fp);
	emxDestroyArray_real_T(Qd1);
	emxDestroyArray_real_T(Id1);

	test_terminate();
	return 0;
}
