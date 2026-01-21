defmodule Solution do
  @spec contains_duplicate(nums :: [integer]) :: boolean
  def contains_duplicate(nums) do
    Enum.reduce_while(nums, MapSet.new(), fn x, seen ->
      if MapSet.member?(seen, x) do
        {:halt, true}
      else
        {:cont, MapSet.put(seen, x)}
      end
    end) == true
  end
end
