# How we solve rigid body collision?

## Insertion

When two objects are approaching, we will allow them insert into each other.

## Resilience

But once we detect that any part of a object is in the interior of another object, we will apply a  resilience force whose magnitude is large enough. Such than both objects will gain acceleration which is parallel to the normal vector of the contact surface.

## Change of velocity and angular velocity

Easy to calculate, using the mass and moment of inertia of the object.

## Conservation of Energy

But when shall we stop applying the resilience? When the kinetic energy of two objects has recovered to identical magnitude before collision assuming perfect elastic collision. (If not, the threshold becomes initial kinetic energy multiplied by a constant, which is related to the recovery coefficient of two objects)
