class Customer 
  attr_accessor :items, :discount_rate, :total
  attr_reader :id,:name, :surname
  def initialize(id, name, surname, items = [], discount_rate = 0.0, total = 0.0)
    @id = id
    @name = name 
    @surname = surname
    @items = items
    @discount_rate = discount_rate
    @total = total
  end
  def to_h
    { id: @id,
      name: @name,
      surname: @surname,
      items: @items.map(&:to_h),
      discount_rate: @discount_rate,
      total: @total
    }
  end
end
