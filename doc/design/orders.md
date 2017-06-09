Orders
======

The orders should be simple and general but very clear.

This permit some discretion on the part of the commander
of the unit. It should not prescribe how to act, just the
result of the action or the intent of the action.

Examples from the wargame rule book are:

Advance and attack enemy to your front.
Demonstrate against the village on the left.
Occupy and hold the round topped hill.
Drive the enemy out of the wood.
Support the Fusiliers.
Remain in reserve.
Delay any enemy attack.
Hold on to the last man. (Yeah, right, general.)

These are very general and not natural to parse with flex and
bison. However, they are pretty much how I want to be able
to enter orders. Not at all prescriptive, concise, but general 
enough to allow the unit's commanding officer some flexibility.

The target for an order must be selected. Should this be part
of the order, thus:

<unit> <order>.

Or should the unit be selected on screen, then the order given?

In reality you tell a messenger or one of your entourage where
you want them to deliver the message, so either is ok.

The orders do not have to be free format entry. They can be 
pre-canned. Many of the above would make sense in multiple
situations. 

Having spent a little time tinkering with the order definition
and using bison it feels very much that using bison makes the 
orders too tied in with a formal layout. It would be nicer to 
permit more free format entry and not hard code meaning and format 
in the same component.

I think I will experiment with this approach and see where it
goes. The flex scanner can still be used to break the input into
words and a more loose parser will have to be hand carved.

