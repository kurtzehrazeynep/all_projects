require 'minitest/autorun'
require_relative 'shopping-cart'
#downcase yapıcaz unutma en son
class TestShoppingCart < Minitest::Test
  def setup #sıfırlamak için her şeyi
    @shoppingcart = ShoppingCart.new
    @shoppingcart.product.clear
    @shoppingcart.customer.clear
  end
  def test_add_customer
    @shoppingcart.add_customer("M1","zehra","kurt")
    @shoppingcart.add_customer("M1","zehra","kurt")#There cannot be two people with the same ID.
    @shoppingcart.add_customer("M1","melike","kurt")#There cannot be two people with the same ID.
    @shoppingcart.add_customer("M2","zehra","kurt") #There could be different individuals with the same name but different IDs.

    assert_equal 2, @shoppingcart.customer.length, "The number of customers must be 2."
  end
  def test_add_product
    @shoppingcart.add_product(3,"Mechanical Keyboard", 120.0)
    @shoppingcart.add_product(1,"MacBook Pro", 1500.0)
    @shoppingcart.add_product(1,"Wireless Mouse", 50.0) #There cannot be two products with the same ID.
    assert_equal 2, @shoppingcart.product.length, "There cannot be two products with the same ID."
    @shoppingcart.add_product(2,"MacBook Pro", 1500.0) #It could be the same product with a different ID.
    assert_equal 3, @shoppingcart.product.length, "It could be the same product with a different ID."
  end
  def test_add_product_to_cart
    customer1 = @shoppingcart.add_customer("M1","zehra","kurt")
    customer2 = @shoppingcart.add_customer("M2","melike","kurt")

    @shoppingcart.add_product(1,"MacBook Pro", 1500.0)

    @shoppingcart.add_product_cart(1,customer1)
    @shoppingcart.add_product_cart(1,customer2)
    assert_equal 1, customer1.items.length, "Two products with the same ID cannot be purchased."
    assert_equal 0, customer2.items.length, "Two products with the same ID cannot be purchased."
    
    @shoppingcart.add_product_cart(2,customer1)
    assert_equal 1, customer1.items.length, "The product not in stock could not be added to the cart."
  end
  def test_remove_product
    @shoppingcart.add_product(1,"MacBook Pro", 1500.0)
    @shoppingcart.add_product(2,"Mechanical Keyboard", 120.0)

    customer = @shoppingcart.add_customer("M1","zehra","kurt")

    @shoppingcart.add_product_cart(1,customer)
    @shoppingcart.add_product_cart(2,customer)

    @shoppingcart.remove_product(1,customer)
    @shoppingcart.remove_product(1,customer) #A returned product cannot be returned again.
    assert_equal 1,customer.items.length, "A returned product cannot be returned again."
    
    @shoppingcart.add_product_cart(1,customer)
    assert_equal 2, customer.items.length, "Returned products can be added back to the cart."
  end 
  def apply_coupon
    @shoppingcart.add_product(1,"MacBook Pro", 1500.0)
    @shoppingcart.add_product(2,"Mechanical Keyboard", 120.0)
     
    customer = @shoppingcart.add_customer("M1","zehra","kurt")
 
    @shoppingcart.add_product_cart(1,customer)
    assert_equal 1500, customer.total,"The discount rate is currently 0.0; this is the total price of the products."
    
    code = "INCORRECTCODE"
    @shoppingcart.apply_coupon(code,customer)
    asser_equal 1500, customer.total, "Incorrect coupon (no discount = 0.0=)"

    code = SAVE10
    assert_equal 1350, customer.total, "correct coupon code (discount rate = 0.1)"
    
    @shoppingcart.add_product_cart(2,customer)
    assert_equal 1458, customer.total, "The coupon applies to all products added to the cart, even if added after the time of application."
  end
  def test_buy
    product = @shoppingcart.add_product(1,"MacBook Pro", 1500.0)
    
    customer1 = @shoppingcart.add_customer("M1","zehra","kurt")
    customer2 = @shoppingcart.add_customer("M2","melike","kurt")
    
    assert product.state, "Product inventory status: true"

    @shoppingcart.add_product_cart(1,customer1)
    @shoppingcart.checkout(customer1)

    refute product.state, "Product is not in inventory; status is true."

    assert_equal 0, customer1.items.length, "The cart is emptied after the purchase."
    assert_equal 0.0, customer1.total, "The total resets to zero (0.0) after the purchase."
    
    @shoppingcart.add_product_cart(1,customer2)
    assert_equal 0, customer2.items.length ,"The purchased item cannot be purchased again (with the same ID)."

  end
end