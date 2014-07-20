#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        int MaxProfit = 0;              /**< Accum of profit. Initial is 0. */
        int VecSize = prices.size();    /**< Num of days. */
        bool hold = false;              /**< Hold the stock. */
        int BuyPrice;                   /**< Current Buy-In price. */
        int current;                    /**< Current stock price. */
        int next;                       /**< Next day stock price. */
        int i;                          /**< Cursor. */
        
        for (i = 0; i < VecSize-1; i++) {
            current = prices.at(i);
            next = prices.at(i+1);
            // If having stock currently and 
            // current stock price is higher than
            // Buy_In price. Sell the stock and 
            // increase the profit.
            if (hold && current > BuyPrice) {
                MaxProfit += BuyPrice - prices.at(i);
                hold = false;
            }   
            // If next day price is higher than 
            // current and not holding the stock,
            // buy the stock at current price.
            if (current < next) {
                if(!hold) {
                    BuyPrice = prices.at(i);
                    std::cout <<"Buy at" << BuyPrice<< std::endl;
                    hold = true;
                } 
            }
        }
        // If hold the stock and last day price is higher
        // than Buy_In price, sell the stock and increase
        // profit.
        if (hold) {
            std::cout << "profit: "<< MaxProfit << std::endl;
            MaxProfit += prices.at(VecSize - 1) - BuyPrice;
            std::cout << "profit: " << MaxProfit << std::endl;
        }
        return MaxProfit;
    }
};

int main ()
{
  Solution sol;
  std::vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(4);
  std::cout << sol.maxProfit(a) << std::endl;
  return 0;
}
