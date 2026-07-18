require_relative 'shopping-cart'
system = ShoppingCart.new

 system.add_product(1,"MacBook Pro", 1500.0)
 system.add_product(2,"Wireless Mouse", 50.0)
 system.add_product(3,"Mechanical Keyboard", 120.0)

  customer = nil
  loop do
  puts "1. Please log in as a customer.\n"
  print "Enter Customer ID: "
  id = gets.chomp
  print  "Enter name: "
  name = gets.chomp
  print "Enter Surname: "
  surname = gets.chomp.to_s
  customer = system.add_customer(id,name,surname)
  if customer.nil?
    puts "⚠️Incorrect ID. Please enter it again."
  else 
    break
  end
end

loop do
  print "\n=== SHOPPİNG CART & JSON TEST MENU ==="
  print "\n1. Add Product to Cart"
  print "\n2. Remove Product"
  print "\n3. Apply Coupon"
  print "\n4. Buy"
  print "\n5. QUİT"
  choice = gets.chomp
  print "your choice: #{choice}\n" 
  case choice 
  when "1"
  print "Enter Product ID: "
  id = gets.chomp
  system.add_product_cart(id,customer)
  when "2"
   print "Enter Produc ID: "
   id = gets.chomp
  system.remove_product(id, customer)
  when "3"
    print "Enter coupen code: "
    code = gets.chomp.to_s
    system.apply_coupon(code,customer)
  when "4"
    system.checkout(customer)
  when "5"
  break
  else
  puts "\nInvalid Option!"
  end
end
 
