### Serial implementation
```
[maria.covaliu@dp-wn03 cmake]$ time ./benchmark 1000 500 3 1

real	0m39.567s
user	0m39.542s
sys	0m0.014s
```
### Iteration 1. Adding OpenMP tasks
```
[maria.covaliu@dp-wn03 cmake]$ time ./benchmark 1000 500 3 2

real	0m26.538s
user	0m47.448s
sys	0m0.125s
[maria.covaliu@dp-wn03 cmake]$ time ./benchmark 1000 500 3 4

real	0m19.392s
user	1m0.564s
sys	0m0.218s
[maria.covaliu@dp-wn03 cmake]$ time ./benchmark 1000 500 3 8

real	0m14.935s
user	1m20.172s
sys	0m0.375s
[maria.covaliu@dp-wn03 cmake]$ time ./benchmark 1000 500 3 16

real	0m13.046s
user	2m2.507s
sys	0m0.594s
[maria.covaliu@dp-wn03 cmake]$ time ./benchmark 1000 500 3 24

real	0m11.868s
user	2m38.536s
sys	0m0.522s
```

### Initial parallization
```
[maria.covaliu@dp-wn03 cmake]$ time ./benchmark 1000 500 3 2

real	0m35.127s
user	0m44.272s
sys	0m0.017s
[maria.covaliu@dp-wn03 cmake]$ time ./benchmark 1000 500 3 4

real	0m32.438s
user	0m48.730s
sys	0m0.037s
[maria.covaliu@dp-wn03 cmake]$ time ./benchmark 1000 500 3 8

real	0m30.316s
user	0m54.943s
sys	0m0.085s
[maria.covaliu@dp-wn03 cmake]$ time ./benchmark 1000 500 3 16

real	0m29.445s
user	1m19.154s
sys	0m0.113s
[maria.covaliu@dp-wn03 cmake]$ time ./benchmark 1000 500 3 24

real	0m30.016s
user	1m43.877s
sys	0m0.159s
```
