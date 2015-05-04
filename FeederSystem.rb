require 'timeout'
require './Repository.rb'
require './Bowl.rb'

class FeederSystem
    attr_reader :repository
    attr_reader :bowls

    @@eating_times = [14, 15, 16, 17, 18, 19, 31, 32]

    @@WEIGHT_OF_FOOD = 2
    @@seconds_elapsed = 0

    def initialize
        @repository = Repository.new
        @bowls = [Bowl.new, Bowl.new]
    end

    def start_timer
        loop do
            on_timer
            sleep(1)
        end
    end

    def on_timer
        @@seconds_elapsed += 1
        gravity_happens
        update_ui

        end_filling_bowls
        if feeding_time?
            begin_filling_bowls
        end

        if eating_time?
            eat
        end
    end

    def gravity_happens
        (0..@repository.chutes.length-1).each do |index|
            chute = @repository.chutes[index]
            if chute.open? && ! @repository.empty?
                @repository.scale.load_sensor.value -= @@WEIGHT_OF_FOOD
                @bowls[index].scale.load_sensor.value += @@WEIGHT_OF_FOOD
            end
        end
    end

    def update_ui
        puts "#{@@seconds_elapsed}s >\tLeft: #{@bowls[0].weight}(#{bowls[0].percent_full}%)\tRight: #{@bowls[1].weight}(#{bowls[1].percent_full}%)\tRepo: #{@repository.weight}(#{repository.percent_full}%)"
    end

    def feeding_time?
        @@seconds_elapsed % 10 === 0
    end

    def begin_filling_bowls
        (0..@bowls.length-1).each do |index|
            bowl = @bowls[index]

            # Check if bowl is already full
            if bowl.full?
                puts "Bowl #{index} already full. Skipping."
                next
            end

            # Fill
            puts "Filling bowl #{index}."
            @repository.chutes[index].open
        end
    end

    def end_filling_bowls
        (0..@bowls.length-1).each do |index|
            if @repository.chutes[index].open? &&  @bowls[index].full?
                @repository.chutes[index].close 
                puts "Done filling bowl #{index}."
            end
        end
    end

    def eating_time?
        @@eating_times.include?(@@seconds_elapsed)
    end

    def eat
        @bowls[0].scale.load_sensor.value -= @@WEIGHT_OF_FOOD unless @bowls[0].empty?
        @bowls[1].scale.load_sensor.value = @bowls[1].scale.load_sensor.value >= ( 2 * @@WEIGHT_OF_FOOD) ?
            @bowls[1].scale.load_sensor.value - ( 2 * @@WEIGHT_OF_FOOD ) :
            0
    end
end