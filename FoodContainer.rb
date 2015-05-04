require './Scale.rb'

class FoodContainer
    attr_reader :scale
    
    @min_weight = 0
    @max_weight = 100

    def initialize
        @scale = Scale.new
    end

    def weight
        @scale.weight
    end

    def tare
        @min_weight = weight
        puts "Tare: #{@min_weight}"
    end

    def set_max
        @max_weight = weight
        puts "Max: #{@max_weight}"
    end

    def empty?
        weight <= @min_weight
    end

    def full?
        weight >= @max_weight
    end

    def percent_full
        (weight.to_f / @max_weight * 100).to_i
    end

end