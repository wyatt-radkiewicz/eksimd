#pragma once
// version 2.0.0x (edited to limit to 512 tests for compilation speed)
// Examples:
// #include "test.h"
// 
// test(always_passes) {
// 	pass;
// }
// test(always_fails) {
// 	fail;
// }
// test(asserts_always) {
// 	assert(5 == 4);
// 	pass;
// }
// test(asserts_message) {
// 	assert(5 == 4, "Wow this was dumb.");
// 	pass;
// }
// 
// const volatile char *strings[] = {
// 	"0.5",
// 	"0.6",
// 	"0.7",
// 	"0.8",
// };
// 
// bench_on(strtod1, strings, 10000) {
// 	// Use the built-in i parameter to get the current thing you are
// 	// looping over
// 	strtod((const char *)*i, NULL);
// }
// bench_for(strtod2, 10000) {
// 	strtod("0.4", NULL);
// }
//

#define _test_concat1(_0, _1) _0##_1
#define _test_concat(_0, _1) _test_concat1(_0, _1)

#define test(_name)                                                            \
	static int test_##_name(void);                                         \
	_test_t _test_concat(_test, __COUNTER__) = {                           \
		.testfn = test_##_name, .istest = true, .name = #_name};       \
	static int test_##_name(void)

#define bench_for(_name, _times)                                               \
	static void bench_##_name(void *);                                     \
	_test_t _test_concat(_test, __COUNTER__) = {                           \
		.bench =                                                       \
			{                                                      \
				.fn = bench_##_name,                           \
				.iters = _times,                               \
				.nitems = 1,                                   \
				},                                                     \
		.name = #_name \
	      };                                               \
	static void bench_##_name(void *_______)
#define bench_on(_name, _array, _times)                                        \
	static void bench_##_name(typeof((_array)[0]) *const);                 \
	_test_t _test_concat(_test, __COUNTER__) = {                           \
		.bench =                                                       \
			{                                                      \
				.fn = (_test_bench_fn *)bench_##_name,         \
				.array = _array,                               \
				.step = sizeof((_array)[0]),                   \
				.nitems =                                      \
					sizeof(_array) / sizeof((_array)[0]),  \
				.iters = _times,                               \
				},                                                     \
		.name = #_name \
	      };                                               \
	static void bench_##_name(typeof((_array)[0]) *const i)

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>

#define pass return 0
#define fail return __LINE__
#define assert(_cond, ...)                                                     \
	if (!(_cond)) {                                                        \
		printf(" Assertion failed: " __VA_ARGS__);                     \
		printf("\n");                                                  \
		fail;                                                          \
	}

typedef int(_test_fn)(void);
typedef void(_test_bench_fn)(void *);

typedef struct _test_bench {
	_test_bench_fn *fn;
	void *array;
	size_t step, nitems, iters;
} _test_bench_t;

typedef struct _test {
	union {
		_test_fn *testfn;
		_test_bench_t bench;
	};
	const char *name;
	bool istest;
} _test_t;

typedef struct _test_state {
	_test_t *benches[1024];
	int passed, ran, nbenches;
} _test_state_t;

static void _test_run_bench(const char *name, _test_bench_t *bench) {
	clock_t start = clock();
	const uintptr_t array_end =
		(uintptr_t)bench->array + bench->nitems * bench->step;
	for (size_t i = 0; i < bench->iters; i++) {
		for (uintptr_t addr = (uintptr_t)bench->array; addr < array_end;
		     addr += bench->step) {
			bench->fn((void *)addr);
		}
	}
	clock_t end = clock();

	printf("\x1B[34m[RAN]\x1B[0m %s (%-8zd iters) in ",
	       name,
	       bench->iters * bench->nitems);

	double secs = ((double)end - (double)start) / (double)CLOCKS_PER_SEC;
	if (secs < 1.0 / 1000.0) printf("%6.2fus ", secs * 1000000.0);
	else printf("%6.2fms ", secs * 1000.0);

	secs /= (double)(bench->iters * bench->nitems);
	printf("(");
	if (secs < 1.0 / 1000.0) printf("%6.2fus ", secs * 1000000.0);
	else printf("%6.2fms ", secs * 1000.0);
	printf("per iter)\n");
}

static bool _test_run(_test_t *test, _test_state_t *state) {
	int fail_line = test->testfn();
	printf("%s\x1B[0m %s",
	       !fail_line ? "\x1B[32m[PASS]" : "\x1B[31m[FAIL]",
	       test->name);
	if (fail_line) printf(" (on line %d)", fail_line);
	printf("\n");
	state->passed += !fail_line, state->ran++;
	return !fail_line;
}

static void _test_start(_test_state_t *state) {
	memset(state, 0, sizeof(*state));
}

static int _test_end(_test_state_t *state) {
	printf("%d/%d tests passed\n", state->passed, state->ran);

	// Run benchmarks if there is any
	if (state->nbenches) printf("\n");
	for (int i = 0; i < state->nbenches; i++) {
		_test_run_bench(
			state->benches[i]->name, &state->benches[i]->bench);
	}

	return state->passed == state->ran ? 0 : 1;
}

#define _test_tryrun(_test)                                                    \
	if (_test.istest) {                                                    \
		_test_run(&_test, state);                                      \
	} else {                                                               \
		if (!_test.bench.fn) return;                                   \
		state->benches[state->nbenches++] = &_test;                    \
	}

static void _tests_run_tests(_test_state_t *state);

int main(int argc, char **argv) {
	_test_state_t state;
	_test_start(&state);
	_tests_run_tests(&state);
	return _test_end(&state);
}

_test_t _test0, _test1, _test2, _test3, _test4, _test5, _test6, _test7, _test8,
	_test9, _test10, _test11, _test12, _test13, _test14, _test15, _test16,
	_test17, _test18, _test19, _test20, _test21, _test22, _test23, _test24,
	_test25, _test26, _test27, _test28, _test29, _test30, _test31, _test32,
	_test33, _test34, _test35, _test36, _test37, _test38, _test39, _test40,
	_test41, _test42, _test43, _test44, _test45, _test46, _test47, _test48,
	_test49, _test50, _test51, _test52, _test53, _test54, _test55, _test56,
	_test57, _test58, _test59, _test60, _test61, _test62, _test63, _test64,
	_test65, _test66, _test67, _test68, _test69, _test70, _test71, _test72,
	_test73, _test74, _test75, _test76, _test77, _test78, _test79, _test80,
	_test81, _test82, _test83, _test84, _test85, _test86, _test87, _test88,
	_test89, _test90, _test91, _test92, _test93, _test94, _test95, _test96,
	_test97, _test98, _test99, _test100, _test101, _test102, _test103,
	_test104, _test105, _test106, _test107, _test108, _test109, _test110,
	_test111, _test112, _test113, _test114, _test115, _test116, _test117,
	_test118, _test119, _test120, _test121, _test122, _test123, _test124,
	_test125, _test126, _test127, _test128, _test129, _test130, _test131,
	_test132, _test133, _test134, _test135, _test136, _test137, _test138,
	_test139, _test140, _test141, _test142, _test143, _test144, _test145,
	_test146, _test147, _test148, _test149, _test150, _test151, _test152,
	_test153, _test154, _test155, _test156, _test157, _test158, _test159,
	_test160, _test161, _test162, _test163, _test164, _test165, _test166,
	_test167, _test168, _test169, _test170, _test171, _test172, _test173,
	_test174, _test175, _test176, _test177, _test178, _test179, _test180,
	_test181, _test182, _test183, _test184, _test185, _test186, _test187,
	_test188, _test189, _test190, _test191, _test192, _test193, _test194,
	_test195, _test196, _test197, _test198, _test199, _test200, _test201,
	_test202, _test203, _test204, _test205, _test206, _test207, _test208,
	_test209, _test210, _test211, _test212, _test213, _test214, _test215,
	_test216, _test217, _test218, _test219, _test220, _test221, _test222,
	_test223, _test224, _test225, _test226, _test227, _test228, _test229,
	_test230, _test231, _test232, _test233, _test234, _test235, _test236,
	_test237, _test238, _test239, _test240, _test241, _test242, _test243,
	_test244, _test245, _test246, _test247, _test248, _test249, _test250,
	_test251, _test252, _test253, _test254, _test255, _test256, _test257,
	_test258, _test259, _test260, _test261, _test262, _test263, _test264,
	_test265, _test266, _test267, _test268, _test269, _test270, _test271,
	_test272, _test273, _test274, _test275, _test276, _test277, _test278,
	_test279, _test280, _test281, _test282, _test283, _test284, _test285,
	_test286, _test287, _test288, _test289, _test290, _test291, _test292,
	_test293, _test294, _test295, _test296, _test297, _test298, _test299,
	_test300, _test301, _test302, _test303, _test304, _test305, _test306,
	_test307, _test308, _test309, _test310, _test311, _test312, _test313,
	_test314, _test315, _test316, _test317, _test318, _test319, _test320,
	_test321, _test322, _test323, _test324, _test325, _test326, _test327,
	_test328, _test329, _test330, _test331, _test332, _test333, _test334,
	_test335, _test336, _test337, _test338, _test339, _test340, _test341,
	_test342, _test343, _test344, _test345, _test346, _test347, _test348,
	_test349, _test350, _test351, _test352, _test353, _test354, _test355,
	_test356, _test357, _test358, _test359, _test360, _test361, _test362,
	_test363, _test364, _test365, _test366, _test367, _test368, _test369,
	_test370, _test371, _test372, _test373, _test374, _test375, _test376,
	_test377, _test378, _test379, _test380, _test381, _test382, _test383,
	_test384, _test385, _test386, _test387, _test388, _test389, _test390,
	_test391, _test392, _test393, _test394, _test395, _test396, _test397,
	_test398, _test399, _test400, _test401, _test402, _test403, _test404,
	_test405, _test406, _test407, _test408, _test409, _test410, _test411,
	_test412, _test413, _test414, _test415, _test416, _test417, _test418,
	_test419, _test420, _test421, _test422, _test423, _test424, _test425,
	_test426, _test427, _test428, _test429, _test430, _test431, _test432,
	_test433, _test434, _test435, _test436, _test437, _test438, _test439,
	_test440, _test441, _test442, _test443, _test444, _test445, _test446,
	_test447, _test448, _test449, _test450, _test451, _test452, _test453,
	_test454, _test455, _test456, _test457, _test458, _test459, _test460,
	_test461, _test462, _test463, _test464, _test465, _test466, _test467,
	_test468, _test469, _test470, _test471, _test472, _test473, _test474,
	_test475, _test476, _test477, _test478, _test479, _test480, _test481,
	_test482, _test483, _test484, _test485, _test486, _test487, _test488,
	_test489, _test490, _test491, _test492, _test493, _test494, _test495,
	_test496, _test497, _test498, _test499, _test500, _test501, _test502,
	_test503, _test504, _test505, _test506, _test507, _test508, _test509,
	_test510, _test511;

static void _tests_run_tests(_test_state_t *state) {
	_test_tryrun(_test0);
	_test_tryrun(_test1);
	_test_tryrun(_test2);
	_test_tryrun(_test3);
	_test_tryrun(_test4);
	_test_tryrun(_test5);
	_test_tryrun(_test6);
	_test_tryrun(_test7);
	_test_tryrun(_test8);
	_test_tryrun(_test9);
	_test_tryrun(_test10);
	_test_tryrun(_test11);
	_test_tryrun(_test12);
	_test_tryrun(_test13);
	_test_tryrun(_test14);
	_test_tryrun(_test15);
	_test_tryrun(_test16);
	_test_tryrun(_test17);
	_test_tryrun(_test18);
	_test_tryrun(_test19);
	_test_tryrun(_test20);
	_test_tryrun(_test21);
	_test_tryrun(_test22);
	_test_tryrun(_test23);
	_test_tryrun(_test24);
	_test_tryrun(_test25);
	_test_tryrun(_test26);
	_test_tryrun(_test27);
	_test_tryrun(_test28);
	_test_tryrun(_test29);
	_test_tryrun(_test30);
	_test_tryrun(_test31);
	_test_tryrun(_test32);
	_test_tryrun(_test33);
	_test_tryrun(_test34);
	_test_tryrun(_test35);
	_test_tryrun(_test36);
	_test_tryrun(_test37);
	_test_tryrun(_test38);
	_test_tryrun(_test39);
	_test_tryrun(_test40);
	_test_tryrun(_test41);
	_test_tryrun(_test42);
	_test_tryrun(_test43);
	_test_tryrun(_test44);
	_test_tryrun(_test45);
	_test_tryrun(_test46);
	_test_tryrun(_test47);
	_test_tryrun(_test48);
	_test_tryrun(_test49);
	_test_tryrun(_test50);
	_test_tryrun(_test51);
	_test_tryrun(_test52);
	_test_tryrun(_test53);
	_test_tryrun(_test54);
	_test_tryrun(_test55);
	_test_tryrun(_test56);
	_test_tryrun(_test57);
	_test_tryrun(_test58);
	_test_tryrun(_test59);
	_test_tryrun(_test60);
	_test_tryrun(_test61);
	_test_tryrun(_test62);
	_test_tryrun(_test63);
	_test_tryrun(_test64);
	_test_tryrun(_test65);
	_test_tryrun(_test66);
	_test_tryrun(_test67);
	_test_tryrun(_test68);
	_test_tryrun(_test69);
	_test_tryrun(_test70);
	_test_tryrun(_test71);
	_test_tryrun(_test72);
	_test_tryrun(_test73);
	_test_tryrun(_test74);
	_test_tryrun(_test75);
	_test_tryrun(_test76);
	_test_tryrun(_test77);
	_test_tryrun(_test78);
	_test_tryrun(_test79);
	_test_tryrun(_test80);
	_test_tryrun(_test81);
	_test_tryrun(_test82);
	_test_tryrun(_test83);
	_test_tryrun(_test84);
	_test_tryrun(_test85);
	_test_tryrun(_test86);
	_test_tryrun(_test87);
	_test_tryrun(_test88);
	_test_tryrun(_test89);
	_test_tryrun(_test90);
	_test_tryrun(_test91);
	_test_tryrun(_test92);
	_test_tryrun(_test93);
	_test_tryrun(_test94);
	_test_tryrun(_test95);
	_test_tryrun(_test96);
	_test_tryrun(_test97);
	_test_tryrun(_test98);
	_test_tryrun(_test99);
	_test_tryrun(_test100);
	_test_tryrun(_test101);
	_test_tryrun(_test102);
	_test_tryrun(_test103);
	_test_tryrun(_test104);
	_test_tryrun(_test105);
	_test_tryrun(_test106);
	_test_tryrun(_test107);
	_test_tryrun(_test108);
	_test_tryrun(_test109);
	_test_tryrun(_test110);
	_test_tryrun(_test111);
	_test_tryrun(_test112);
	_test_tryrun(_test113);
	_test_tryrun(_test114);
	_test_tryrun(_test115);
	_test_tryrun(_test116);
	_test_tryrun(_test117);
	_test_tryrun(_test118);
	_test_tryrun(_test119);
	_test_tryrun(_test120);
	_test_tryrun(_test121);
	_test_tryrun(_test122);
	_test_tryrun(_test123);
	_test_tryrun(_test124);
	_test_tryrun(_test125);
	_test_tryrun(_test126);
	_test_tryrun(_test127);
	_test_tryrun(_test128);
	_test_tryrun(_test129);
	_test_tryrun(_test130);
	_test_tryrun(_test131);
	_test_tryrun(_test132);
	_test_tryrun(_test133);
	_test_tryrun(_test134);
	_test_tryrun(_test135);
	_test_tryrun(_test136);
	_test_tryrun(_test137);
	_test_tryrun(_test138);
	_test_tryrun(_test139);
	_test_tryrun(_test140);
	_test_tryrun(_test141);
	_test_tryrun(_test142);
	_test_tryrun(_test143);
	_test_tryrun(_test144);
	_test_tryrun(_test145);
	_test_tryrun(_test146);
	_test_tryrun(_test147);
	_test_tryrun(_test148);
	_test_tryrun(_test149);
	_test_tryrun(_test150);
	_test_tryrun(_test151);
	_test_tryrun(_test152);
	_test_tryrun(_test153);
	_test_tryrun(_test154);
	_test_tryrun(_test155);
	_test_tryrun(_test156);
	_test_tryrun(_test157);
	_test_tryrun(_test158);
	_test_tryrun(_test159);
	_test_tryrun(_test160);
	_test_tryrun(_test161);
	_test_tryrun(_test162);
	_test_tryrun(_test163);
	_test_tryrun(_test164);
	_test_tryrun(_test165);
	_test_tryrun(_test166);
	_test_tryrun(_test167);
	_test_tryrun(_test168);
	_test_tryrun(_test169);
	_test_tryrun(_test170);
	_test_tryrun(_test171);
	_test_tryrun(_test172);
	_test_tryrun(_test173);
	_test_tryrun(_test174);
	_test_tryrun(_test175);
	_test_tryrun(_test176);
	_test_tryrun(_test177);
	_test_tryrun(_test178);
	_test_tryrun(_test179);
	_test_tryrun(_test180);
	_test_tryrun(_test181);
	_test_tryrun(_test182);
	_test_tryrun(_test183);
	_test_tryrun(_test184);
	_test_tryrun(_test185);
	_test_tryrun(_test186);
	_test_tryrun(_test187);
	_test_tryrun(_test188);
	_test_tryrun(_test189);
	_test_tryrun(_test190);
	_test_tryrun(_test191);
	_test_tryrun(_test192);
	_test_tryrun(_test193);
	_test_tryrun(_test194);
	_test_tryrun(_test195);
	_test_tryrun(_test196);
	_test_tryrun(_test197);
	_test_tryrun(_test198);
	_test_tryrun(_test199);
	_test_tryrun(_test200);
	_test_tryrun(_test201);
	_test_tryrun(_test202);
	_test_tryrun(_test203);
	_test_tryrun(_test204);
	_test_tryrun(_test205);
	_test_tryrun(_test206);
	_test_tryrun(_test207);
	_test_tryrun(_test208);
	_test_tryrun(_test209);
	_test_tryrun(_test210);
	_test_tryrun(_test211);
	_test_tryrun(_test212);
	_test_tryrun(_test213);
	_test_tryrun(_test214);
	_test_tryrun(_test215);
	_test_tryrun(_test216);
	_test_tryrun(_test217);
	_test_tryrun(_test218);
	_test_tryrun(_test219);
	_test_tryrun(_test220);
	_test_tryrun(_test221);
	_test_tryrun(_test222);
	_test_tryrun(_test223);
	_test_tryrun(_test224);
	_test_tryrun(_test225);
	_test_tryrun(_test226);
	_test_tryrun(_test227);
	_test_tryrun(_test228);
	_test_tryrun(_test229);
	_test_tryrun(_test230);
	_test_tryrun(_test231);
	_test_tryrun(_test232);
	_test_tryrun(_test233);
	_test_tryrun(_test234);
	_test_tryrun(_test235);
	_test_tryrun(_test236);
	_test_tryrun(_test237);
	_test_tryrun(_test238);
	_test_tryrun(_test239);
	_test_tryrun(_test240);
	_test_tryrun(_test241);
	_test_tryrun(_test242);
	_test_tryrun(_test243);
	_test_tryrun(_test244);
	_test_tryrun(_test245);
	_test_tryrun(_test246);
	_test_tryrun(_test247);
	_test_tryrun(_test248);
	_test_tryrun(_test249);
	_test_tryrun(_test250);
	_test_tryrun(_test251);
	_test_tryrun(_test252);
	_test_tryrun(_test253);
	_test_tryrun(_test254);
	_test_tryrun(_test255);
	_test_tryrun(_test256);
	_test_tryrun(_test257);
	_test_tryrun(_test258);
	_test_tryrun(_test259);
	_test_tryrun(_test260);
	_test_tryrun(_test261);
	_test_tryrun(_test262);
	_test_tryrun(_test263);
	_test_tryrun(_test264);
	_test_tryrun(_test265);
	_test_tryrun(_test266);
	_test_tryrun(_test267);
	_test_tryrun(_test268);
	_test_tryrun(_test269);
	_test_tryrun(_test270);
	_test_tryrun(_test271);
	_test_tryrun(_test272);
	_test_tryrun(_test273);
	_test_tryrun(_test274);
	_test_tryrun(_test275);
	_test_tryrun(_test276);
	_test_tryrun(_test277);
	_test_tryrun(_test278);
	_test_tryrun(_test279);
	_test_tryrun(_test280);
	_test_tryrun(_test281);
	_test_tryrun(_test282);
	_test_tryrun(_test283);
	_test_tryrun(_test284);
	_test_tryrun(_test285);
	_test_tryrun(_test286);
	_test_tryrun(_test287);
	_test_tryrun(_test288);
	_test_tryrun(_test289);
	_test_tryrun(_test290);
	_test_tryrun(_test291);
	_test_tryrun(_test292);
	_test_tryrun(_test293);
	_test_tryrun(_test294);
	_test_tryrun(_test295);
	_test_tryrun(_test296);
	_test_tryrun(_test297);
	_test_tryrun(_test298);
	_test_tryrun(_test299);
	_test_tryrun(_test300);
	_test_tryrun(_test301);
	_test_tryrun(_test302);
	_test_tryrun(_test303);
	_test_tryrun(_test304);
	_test_tryrun(_test305);
	_test_tryrun(_test306);
	_test_tryrun(_test307);
	_test_tryrun(_test308);
	_test_tryrun(_test309);
	_test_tryrun(_test310);
	_test_tryrun(_test311);
	_test_tryrun(_test312);
	_test_tryrun(_test313);
	_test_tryrun(_test314);
	_test_tryrun(_test315);
	_test_tryrun(_test316);
	_test_tryrun(_test317);
	_test_tryrun(_test318);
	_test_tryrun(_test319);
	_test_tryrun(_test320);
	_test_tryrun(_test321);
	_test_tryrun(_test322);
	_test_tryrun(_test323);
	_test_tryrun(_test324);
	_test_tryrun(_test325);
	_test_tryrun(_test326);
	_test_tryrun(_test327);
	_test_tryrun(_test328);
	_test_tryrun(_test329);
	_test_tryrun(_test330);
	_test_tryrun(_test331);
	_test_tryrun(_test332);
	_test_tryrun(_test333);
	_test_tryrun(_test334);
	_test_tryrun(_test335);
	_test_tryrun(_test336);
	_test_tryrun(_test337);
	_test_tryrun(_test338);
	_test_tryrun(_test339);
	_test_tryrun(_test340);
	_test_tryrun(_test341);
	_test_tryrun(_test342);
	_test_tryrun(_test343);
	_test_tryrun(_test344);
	_test_tryrun(_test345);
	_test_tryrun(_test346);
	_test_tryrun(_test347);
	_test_tryrun(_test348);
	_test_tryrun(_test349);
	_test_tryrun(_test350);
	_test_tryrun(_test351);
	_test_tryrun(_test352);
	_test_tryrun(_test353);
	_test_tryrun(_test354);
	_test_tryrun(_test355);
	_test_tryrun(_test356);
	_test_tryrun(_test357);
	_test_tryrun(_test358);
	_test_tryrun(_test359);
	_test_tryrun(_test360);
	_test_tryrun(_test361);
	_test_tryrun(_test362);
	_test_tryrun(_test363);
	_test_tryrun(_test364);
	_test_tryrun(_test365);
	_test_tryrun(_test366);
	_test_tryrun(_test367);
	_test_tryrun(_test368);
	_test_tryrun(_test369);
	_test_tryrun(_test370);
	_test_tryrun(_test371);
	_test_tryrun(_test372);
	_test_tryrun(_test373);
	_test_tryrun(_test374);
	_test_tryrun(_test375);
	_test_tryrun(_test376);
	_test_tryrun(_test377);
	_test_tryrun(_test378);
	_test_tryrun(_test379);
	_test_tryrun(_test380);
	_test_tryrun(_test381);
	_test_tryrun(_test382);
	_test_tryrun(_test383);
	_test_tryrun(_test384);
	_test_tryrun(_test385);
	_test_tryrun(_test386);
	_test_tryrun(_test387);
	_test_tryrun(_test388);
	_test_tryrun(_test389);
	_test_tryrun(_test390);
	_test_tryrun(_test391);
	_test_tryrun(_test392);
	_test_tryrun(_test393);
	_test_tryrun(_test394);
	_test_tryrun(_test395);
	_test_tryrun(_test396);
	_test_tryrun(_test397);
	_test_tryrun(_test398);
	_test_tryrun(_test399);
	_test_tryrun(_test400);
	_test_tryrun(_test401);
	_test_tryrun(_test402);
	_test_tryrun(_test403);
	_test_tryrun(_test404);
	_test_tryrun(_test405);
	_test_tryrun(_test406);
	_test_tryrun(_test407);
	_test_tryrun(_test408);
	_test_tryrun(_test409);
	_test_tryrun(_test410);
	_test_tryrun(_test411);
	_test_tryrun(_test412);
	_test_tryrun(_test413);
	_test_tryrun(_test414);
	_test_tryrun(_test415);
	_test_tryrun(_test416);
	_test_tryrun(_test417);
	_test_tryrun(_test418);
	_test_tryrun(_test419);
	_test_tryrun(_test420);
	_test_tryrun(_test421);
	_test_tryrun(_test422);
	_test_tryrun(_test423);
	_test_tryrun(_test424);
	_test_tryrun(_test425);
	_test_tryrun(_test426);
	_test_tryrun(_test427);
	_test_tryrun(_test428);
	_test_tryrun(_test429);
	_test_tryrun(_test430);
	_test_tryrun(_test431);
	_test_tryrun(_test432);
	_test_tryrun(_test433);
	_test_tryrun(_test434);
	_test_tryrun(_test435);
	_test_tryrun(_test436);
	_test_tryrun(_test437);
	_test_tryrun(_test438);
	_test_tryrun(_test439);
	_test_tryrun(_test440);
	_test_tryrun(_test441);
	_test_tryrun(_test442);
	_test_tryrun(_test443);
	_test_tryrun(_test444);
	_test_tryrun(_test445);
	_test_tryrun(_test446);
	_test_tryrun(_test447);
	_test_tryrun(_test448);
	_test_tryrun(_test449);
	_test_tryrun(_test450);
	_test_tryrun(_test451);
	_test_tryrun(_test452);
	_test_tryrun(_test453);
	_test_tryrun(_test454);
	_test_tryrun(_test455);
	_test_tryrun(_test456);
	_test_tryrun(_test457);
	_test_tryrun(_test458);
	_test_tryrun(_test459);
	_test_tryrun(_test460);
	_test_tryrun(_test461);
	_test_tryrun(_test462);
	_test_tryrun(_test463);
	_test_tryrun(_test464);
	_test_tryrun(_test465);
	_test_tryrun(_test466);
	_test_tryrun(_test467);
	_test_tryrun(_test468);
	_test_tryrun(_test469);
	_test_tryrun(_test470);
	_test_tryrun(_test471);
	_test_tryrun(_test472);
	_test_tryrun(_test473);
	_test_tryrun(_test474);
	_test_tryrun(_test475);
	_test_tryrun(_test476);
	_test_tryrun(_test477);
	_test_tryrun(_test478);
	_test_tryrun(_test479);
	_test_tryrun(_test480);
	_test_tryrun(_test481);
	_test_tryrun(_test482);
	_test_tryrun(_test483);
	_test_tryrun(_test484);
	_test_tryrun(_test485);
	_test_tryrun(_test486);
	_test_tryrun(_test487);
	_test_tryrun(_test488);
	_test_tryrun(_test489);
	_test_tryrun(_test490);
	_test_tryrun(_test491);
	_test_tryrun(_test492);
	_test_tryrun(_test493);
	_test_tryrun(_test494);
	_test_tryrun(_test495);
	_test_tryrun(_test496);
	_test_tryrun(_test497);
	_test_tryrun(_test498);
	_test_tryrun(_test499);
	_test_tryrun(_test500);
	_test_tryrun(_test501);
	_test_tryrun(_test502);
	_test_tryrun(_test503);
	_test_tryrun(_test504);
	_test_tryrun(_test505);
	_test_tryrun(_test506);
	_test_tryrun(_test507);
	_test_tryrun(_test508);
	_test_tryrun(_test509);
	_test_tryrun(_test510);
	_test_tryrun(_test511);
}
