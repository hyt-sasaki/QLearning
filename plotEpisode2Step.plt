set terminal postscript eps color enhanced "Arial" 35
#出力ファイル名
set output "result.eps"
#x軸ラベル
set xlabel "episode"
#y軸ラベル
set ylabel "step"
#x軸目盛り間隔
#set xtics 2
#y軸目盛り間隔
#set ytics 200
#set yrange [0.75:1]
#凡例の位置
set key right top
#プロット
plot 'result.dat' using 1:2 w l lt rgb "red" lw 2 title "result"
#画像のフォーマットを変換
#!convert -density 216 ann_accuracy1.eps ann_accuracy1.png
#pause -1
