require './FoodContainer.rb'
require './Chute.rb'

class Repository < FoodContainer
    attr_accessor :chutes

    def initialize
        super
        @chutes = [Chute.new, Chute.new]
    end
end