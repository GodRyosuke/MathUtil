# 自作GLMライブラリ
GLMに搭載している、ベクトル演算、行列演算関連の処理をまとめたリポジトリである。
現段階では、Windowsのみ対応。

## Prerequests
MinGWをインストールし、環境変数を通しておく。

## build
```bash
mkdir build
cd build
cmake -S .. -B . -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

