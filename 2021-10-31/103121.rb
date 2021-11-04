class MyLinkedListNode
  attr_accessor :data, :next
  def initialize(data, link=nil)
    @data = data
    @link = link
  end
  
end

class MyLinkedList
  def initialize(nodes)
    @head = nil
    @tail = nil
    @nodes = []
  end 

  def append(data)
  end
end

n = MyLinkedListNode.new("Joel")
puts "data: #{n.data}"
puts "next: #{n.next}"
