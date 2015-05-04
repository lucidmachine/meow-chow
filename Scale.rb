require './LoadSensor.rb'

class Scale

    attr_accessor :load_sensor
    attr_reader :weight

    def initialize
        puts "Initializing scale."
        @load_sensor = LoadSensor.new
    end

    def weight
        @weight = @load_sensor.value
    end

end