class Chute

    @is_open = false

    def open
        @is_open = true
    end

    def close
        @is_open = false
    end

    def open?
        @is_open
    end

    def closed?
        ! open?
    end

end