class Product
  attr_accessor :state
  attr_reader :name, :price, :id

  def initialize(id,name, price,state = true)
    @id = id
    @name = name
    @price = price
    @state = state
  end
   def to_h
     {
      id: @id,
      name: @name,
      price: @price,
      state: @state
     }
   end
end