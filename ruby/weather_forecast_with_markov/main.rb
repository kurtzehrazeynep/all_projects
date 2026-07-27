puts "Please enter the initial probabilities separated by commas, for example (0.3, 0.1, 0.6)."
pi = gets.chomp.split(",").map { |x| x.strip.to_f}
j_current = pi
puts "How many days ahead should the forecast be made? : "
step_count = gets.chomp.to_i
puts "-"*122
puts "-"*42+"☀️"+"-"*26+"☁️"+"-"*27+"🌧️"+"-"*24
puts "Today's weather forecast :"+"-"*16+"#{pi[0]}"+"-"*24+"#{pi[1]}"+"-"*25+"#{pi[2]}"+"-"*22
matris = [
    [0.6 , 0.3 , 0.1],
    [0.3 , 0.4 , 0.3],
    [0.2 , 0.3 , 0.5]
]


def matris_carpim (matris,j)
    sonuc = []
  (0..2).each do |i|
    toplam = 0
  (0..2).each do |k|
    toplam += matris[k][i]*j[k]
   end
  sonuc  << toplam.round(4)
  end
 sonuc
end

puts "-"*122
step_count.times do |n|
  j_current = matris_carpim(matris,j_current)
  puts "End of Day #{n+1} Probabilities: (Sunny, Cloudy, Rainy) : #{j_current.inspect}"
end
puts "-"*122
