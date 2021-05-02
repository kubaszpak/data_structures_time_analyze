import matplotlib.pyplot as plt

plt.plot([100000, 200000, 300000, 400000, 500000], [
         0.04, 0.25, 0.38, 0.5, 0.69], 'b-', label='Dynamic Array')
plt.plot([100000, 200000, 300000, 400000, 500000], [
         60 / 1000000, 61 / 1000000, 60 / 1000000, 59 / 1000000, 59 / 1000000], 'r-', label='Doubly Linked List')
plt.plot([100000, 200000, 300000, 400000, 500000], [
         0.04, 0.28, 0.45, 0.57, 0.79], 'y-', label='Heap')
plt.plot([100000, 200000, 300000, 400000, 500000], [
         250 / 1000000, 380 / 1000000, 520 / 1000000, 640 / 1000000, 850 / 1000000], 'k-', label='Binary Search Tree')
plt.title('Time of one addition to a data structure')
plt.xlabel('Amount of data in the structre beforehand')
plt.ylabel('Time [ms]')
# plt.ylim([0, 100])

plt.legend()
plt.show()
