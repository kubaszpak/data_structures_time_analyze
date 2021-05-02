import matplotlib.pyplot as plt

plt.plot([100000, 200000, 300000, 400000, 500000], [
         5.8, 7, 7.7, 7.8, 8], 'b-', label='Dynamic Array')
plt.plot([100000, 200000, 300000, 400000, 500000], [
         58, 70.1, 76.3, 79.5, 80], 'r-', label='Doubly Linked List')
plt.plot([100000, 200000, 300000, 400000, 500000], [
         0.1, 0.1, 0.2, 0.2, 0.2], 'k-', label='Binary Search Tree')
plt.title('Time of one search in a data structure')
plt.xlabel('Amount of data in the structre beforehand')
plt.ylabel('Time [us] - microseconds')
# plt.ylim([100, 200])

plt.legend()
plt.show()
