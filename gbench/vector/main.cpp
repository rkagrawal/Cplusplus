// Adding Pause and ResumeTimeing actually increases the time as these calls take more more time than the actual work

#include<benchmark/benchmark.h>
#include<iostream>
#include<memory>
#include<vector>

void BM_VecOfSharedPtr(benchmark::State& state) {

	int veclen = state.range(0);
	std::vector<std::shared_ptr<std::pair<int,int>>> spvec;
	spvec.reserve(veclen);

	for(int i=0; i< veclen ; i++ ) {
		int val1 =  rand() % 200;
		int val2 =  rand() % 200;
		spvec.push_back( std::make_shared<std::pair<int,int>>(val1, val2 ) );
	}


	for( auto _ : state ) {
		//state.PauseTiming();
		int idx = rand() % veclen;
		//state.ResumeTiming();
		int l = spvec[idx]->first ;
		int u = spvec[idx]->second;
	}
}

void BM_VecOfPair(benchmark::State& state) {

	int veclen = state.range(0);
	std::vector<std::pair<int,int>> spvec;
	spvec.reserve(veclen);

	for(int i=0; i< veclen ; i++ ) {
		int val1 =  rand() % 200;
		int val2 =  rand() % 200;
		spvec.push_back( std::pair<int,int>(val1, val2 ) );
	}


	for( auto _ : state ) {
		//state.PauseTiming();
		int idx = rand() % veclen;
		//state.ResumeTiming();
		int l = spvec[idx].first ;
		int u = spvec[idx].second;
	}
}

BENCHMARK(BM_VecOfSharedPtr)->DenseRange(10000, 50000, 10000 );
BENCHMARK(BM_VecOfPair)->DenseRange(10000, 50000, 10000 );

BENCHMARK_MAIN();
