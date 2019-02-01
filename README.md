# CS143-Stanford
My personal records while learning CS143 Compilers of Stanford

# Resources
[Stanford's MOOC](https://lagunita.stanford.edu/courses/Engineering/Compilers/Fall2014/info)  
[Stanford offical](http://web.stanford.edu/class/cs143/)

# COOLA the language example
```
-------------- Test code -------------

(class (: Test Set) (: n Int)
  (= id n)
  (: test (-> Test Bool))
  (: main (-> (List String) (IO)))
  (= (main args)
    (print (fst args)))
)

(class (: Testable (Test 0)) (: n Int)
  (= (test tt) (== (.id tt) n))
  (= (: debug String)
    (.+ "Testing" (.toString id)))
)


(= (: obj Test) (new (Testable 0)))

(print (.test obj obj))

```


