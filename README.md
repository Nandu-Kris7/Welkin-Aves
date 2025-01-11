# Welkin-Aves
This repository showcases the journey of Welkin Aves, a drone technology project focused on creating innovative solutions for operational efficiency. Development of a drone prototype featuring a cutting-edge battery-swapping mechanism, capable of swapping batteries within 2 minutes. 
Contributions to the field of drone technology through efficient design, embedded systems programming, and CAD modeling.
Key achievements, including raising $12,000 in funding and winning awards like Idea Fest 2021 and Idea Fest 2022, organized by Kerala Startup Mission.

This repository includes every piece of code we used to make the Battery swapping station.

The Battery Swapping station has Five main parts 1) Battery 2) Battery Holder 3) Charger 4) Aligner 5) Leveler

Battery
We modified a 5000mAh 11.1V lithium polymer battery by designing a custom shell that incorporated connecting plates as terminals. The shell was engineered for seamless integration, allowing the battery to be easily removed and swapped into the drone without the need for complex mechanisms or manual intervention.

Battery Holder
The battery holder is a vital component mounted on the main actuator, designed to secure the battery in place and facilitate its seamless movement between the charger and the drone. It incorporates a robust locking mechanism powered by two servo motors on either side, ensuring the battery remains firmly positioned during operation and transit. This design guarantees reliability and efficiency throughout the swapping process.

Charger
We customized a standard LiPo battery charger to align with the design of the battery shell. The charger was modified to include pogo pins that seamlessly connect with the battery's terminal plates, enabling efficient and reliable charging. This design ensures compatibility and simplifies the charging process.

Aligner
The aligner is a critical mechanism that ensures the precise positioning of the drone, enabling the onboard battery to perfectly align with the battery holder in the main actuator for swapping. The system comprises two aligners: a horizontal aligner and a vertical aligner, which work in tandem to adjust the drone’s position. This ensures accurate alignment even if the drone lands at any point within the battery swapping station.
The aligner mechanism is powered by a total of eight linear actuators, all controlled by an Arduino, providing precise and reliable adjustments for seamless operation.

Leveler
The leveler is a mechanism designed to adjust the height of the landing plates where the drone lands. By precisely modifying the height, the leveler ensures that the drone’s battery aligns perfectly with the battery holder for seamless swapping.
This system is powered by four linear actuators, all controlled by an Arduino, enabling accurate height adjustments for optimal alignment during the battery swapping process.

I have attached the CAD images and working of the Battery swapping station
