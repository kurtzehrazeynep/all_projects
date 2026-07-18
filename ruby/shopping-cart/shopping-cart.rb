require 'json'
require_relative 'customer'
require_relative 'product'


class ShoppingCart
  attr_accessor :product, :customer
  attr_reader :saved_customers
    def initialize
      @product = []
      @customer = []
      load_customers_to_json
      load_products_to_json
    end
    def add_product(id,product_name,prize) 
      ex_product = @product.find {|p| p.id.to_s == id.to_s}
      if ex_product
     # puts "⚠️ A product with this ID already exists. Please enter the correct ID."
      return ex_product
      end
      new_product = Product.new(id,product_name,prize)
      @product << new_product
      save_products_to_json
      #puts "Product successfully saved!"
      new_product
    end
 
def add_customer(id, name, surname)
  ex_customer = @customer.find { |c| c.id.to_s == id.to_s && c.name.to_s == name.to_s && c.surname.to_s == surname.to_s}
  return ex_customer if ex_customer
  i_costumer =  @customer.find { |c| c.id.to_s == id.to_s }
  if i_costumer
    return nil
  end

  new_customer = Customer.new(id, name, surname)
  @customer << new_customer
  save_customers_to_json
  puts "customer successfully saved!"
  new_customer
end

    def add_product_cart(product_id,customer_object)
      customer = @customer.find {|c| c.id.to_s == customer_object.id.to_s}
      if !customer
        puts "⚠️ User with this ID not found."
        return
      end
      product = @product.find {|p| p.id.to_s == product_id.to_s}
    if !product
      puts "⚠️ Error: Product not found."
      return
    end
    state = product.state 
    if !state
      puts "⚠️ Error: Product not found.."
      return
    end
    customer.items << product
    product.state = false
    calculate_total(customer)
      calculate_total(customer_object)
    save_products_to_json
    save_customers_to_json
    puts "|#{customer.name} #{customer.surname}|  #{product.name} added to cart. "
    return product
    end

    def remove_product(product_id,customer_object)
      #product_object e göre yapmalısın 
     customer = @customer.find {|c| c.id.to_s == customer_object.id.to_s}
      if !customer
        puts "⚠️ User with this ID not found."
        return
      end
       product = customer_object.items.find {|p| p.id.to_s == product_id.to_s}
      if !product
      puts "⚠️ Product not found in the cart."
        return
      end
      l_product = @product.find {|p| p.id.to_s == product_id.to_s}
        l_product.state = true
        customer.items.delete_if {|item| item.id.to_s == product.id.to_s}
        puts "#{product.name} The product has been removed from the cart."
        calculate_total(customer)
        save_customers_to_json
        save_products_to_json
    end
    def apply_coupon(code,customer_object) #customer nesnesi ustunden gidelim
      customer = @customer.find {|c| c.id.to_s == customer_object.id.to_s}
      if !customer
       puts  "⚠️ User with this ID not found."
        return
      end
       if code == "SAVE10"
         customer.discount_rate = 0.10
         puts "Coupon applied successfully."
       else 
         puts "Invalid coupon code!"
         customer.discount_rate = 0.0
       end
       calculate_total(customer)
       save_customers_to_json
       customer
    end
    def calculate_total(customer)
       customer = @customer.find {|m| m.id.to_s == customer.id.to_s}
       subtotal = customer.items.sum(&:price)
       if !customer.discount_rate
         puts "⚠️ Coupon cannot be applied."
         return subtotal
       end
       total = subtotal - (subtotal*customer.discount_rate)
       customer.total = total
       save_customers_to_json
       total
    end
def checkout(customer_object) #customer nesnesi uzerinden git
  customer = @customer.find { |c| c.id.to_s == customer_object.id.to_s }
  if !customer || customer.items.empty?
    puts "⚠️ Cart is empty or user not found."
    return
  end

  # Kuponu daha önce uygulamış olmalısın, burada sadece hesapla:
  final_amount = calculate_total(customer)
  customer.total = 0.0
  customer.discount_rate = 0.0
  puts "-" * 20 + " #{customer.name}'s Invoice " + "-" * 20
  customer.items.each { |item| puts "#{item.name}: #{item.price}" }
  puts "Total amount:  #{final_amount}"
  
  customer.items.clear # Sepeti temizle
  save_customers_to_json
  
end
  private

  def save_products_to_json
    products_hash_array = @product.map {|p| p.to_h}
    File.write('product.json',JSON.pretty_generate(products_hash_array))
  end
  def save_customers_to_json
    members_hash_array = @customer.map {|p| p.to_h}
    File.write('customers.json',JSON.pretty_generate(members_hash_array))
  end
  def load_products_to_json
    @product = []
    if File.exist?('product.json') && !File.read('product.json').empty?
      begin
        saved_products = JSON.parse(File.read('product.json'))
        saved_products.each do |p|
          state = p['state'] 
          price = p['price']
                @product << Product.new(p['id'],p['name'],price,state)
        end
      rescue JSON::ParserError => e
        puts "⚠️ Error reading products JSON: #{e.message}"
      end
    end
  end
  def load_customers_to_json
    if File.exist?('customers.json') && !File.read('customers.json').empty?
      begin
        saved_customers = JSON.parse(File.read('customers.json'))

        saved_customers.each do |p|
           #hashi nesneye çevirmelisin
           #dıştaki hepsi ama içteki liste için olmalı yoksa ç hash kalır
          i_list_= (p['items'] || []).map do  |item_hash| 
          Product.new(item_hash['id'], item_hash['name'], item_hash['price'], item_hash['state'])
          end

          d_rate = p['discount_rate'] || 0.0
          total = p['total'] || 0.0
         @customer << Customer.new(p['id'], p['name'], p['surname'], i_list_, d_rate,total)
        end
      rescue JSON::ParserError => e
        puts "⚠️ Error reading members JSON: #{e.message}"
      end
    end 
  end

end