[source](http://net.pku.edu.cn/~yhf/tutorial/STL_doc/iterator_traits.html)<br>
<h3>Description</h3>
As described in the <A href="Iterators.html">Iterator Overview</A>, one of the most important
facts about iterators is that they have associated types.  An iterator
type, for example, has an associated <i>value type</i>: the type of
object that the iterator points to.  It also has an associated
<i>distance type</i>, or <i>difference type</i>, a signed integral type that
can be used to represent the distance between two iterators.
<P>
(Pointers, for example, are iterators;  the value type of 
<tt>int*</tt> is <tt>int</tt>.  Its distance type is <tt>ptrdiff_t</tt>, because, if
<tt>p1</tt> and <tt>p2</tt> are pointers, the expression <tt>p1 - p2</tt> has type
<tt>ptrdiff_t</tt>.)
<P>
Generic algorithms often need to have access to these associated
types; an algorithm that takes a range of iterators, for example,
might need to declare a temporary variable whose type is the
iterators' value type.  The class <tt>iterator_traits</tt> is a
mechanism that allows such declarations.
<P>
The most obvious way to allow declarations of that sort would
be to require that all iterators declare nested types; an iterator
<tt>I</tt>'s value type, for example, would be <tt>I::value_type</tt>.  That
can't possibly work, though.  Pointers are iterators, and 
pointers aren't classes; if <tt>I</tt> is (say) <tt>int*</tt>, then it's
impossible to define <tt>I::value_type</tt> to be <tt>int</tt>.
Instead, <tt>I</tt>'s value type is written <tt>iterator_traits&lt;I&gt;::value_type</tt>.
<tt>iterator_traits</tt> is a template class that contains nothing but
nested <tt>typedef</tt>s; in addition to <tt>value_type</tt>, <tt>iterator_traits</tt> 
defines the nested types <tt>iterator_category</tt>, <tt>difference_type</tt>,
<tt>pointer</tt>,  and <tt>reference</tt>.
<P>
The library contains two definitions of <tt>iterator_traits</tt>:
a fully generic one, and a specialization that is used whenever
the template argument is a pointer type <A href="#1">[1]</A>.  The fully 
generic version defines <tt>iterator_traits&lt;I&gt;::value_type</tt> as
a synonym for <tt>I::value_type</tt>, 
<tt>iterator_traits&lt;I&gt;::difference_type</tt>  as a synonym for
<tt>I::difference_type</tt>, and so on.  Since pointers don't have
nested types, <tt>iterator_traits&lt;T*&gt;</tt> has a different definition.
<P>
The implementation of <tt>iterator_traits</tt> is actually simpler 
than this discussion.
<pre>
  template &lt;class Iterator&gt;
  struct iterator_traits {
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::value_type        value_type;
    typedef typename Iterator::difference_type   difference_type;
    typedef typename Iterator::pointer           pointer;
    typedef typename Iterator::reference         reference;
  };

  template &lt;class T&gt;
  struct iterator_traits&lt;T*&gt; {
    typedef random_access_iterator_tag iterator_category;
    typedef T                          value_type;
    typedef ptrdiff_t                  difference_type;
    typedef T*                         pointer;
    typedef T&amp;                         reference;
  };
</pre>
<P>
If you are defining a new iterator type <tt>I</tt>, then you must ensure
that <tt>iterator_traits&lt;I&gt;</tt> is defined properly.  There are two ways
to do this.  First, you can define your iterator so that it has
nested types <tt>I::value_type</tt>, <tt>I::difference_type</tt>, and so on.
Second, you can explicitly specialize <tt>iterator_traits</tt> for your
type.  The first way is almost always more convenient, however,
especially since you can easily ensure that your iterator has
the appropriate nested types just by inheriting from one of the
base classes <tt><A href="input_iterator.html">input_iterator</A></tt>, <tt><A href="output_iterator.html">output_iterator</A></tt>, 
<tt><A href="forward_iterator.html">forward_iterator</A></tt>, <tt><A href="bidirectional_iterator.html">bidirectional_iterator</A></tt>, or
<tt><A href="random_access_iterator.html">random_access_iterator</A></tt>.
<P>
Note that <tt>iterator_traits</tt> is new; it was added to the draft C++
standard relatively recently.  Both the old <A href="iterator_tags.html">iterator tags</A>
mechanism and the new <tt>iterator_traits</tt> mechanism are currently
supported <A href="#1">[1]</A>, but the old iterator tag functions are no longer
part of the standard C++ library and they will eventually be
removed.
<h3>Example</h3>
This generic function returns the last element in a non-empty range.
Note that there is no way to define a function with this interface
in terms of the old <tt><A href="value_type.html">value_type</A></tt> function, because the function's
return type must be declared to be the iterator's value type.
<pre>
template &lt;class InputIterator&gt;
iterator_traits&lt;InputIterator&gt;::value_type
last_value(InputIterator first, InputIterator last) {
  iterator_traits&lt;InputIterator&gt;::value_type result = *first;
  for (++first; first != last; ++first)
    result = *first;
  return result;
}    
</pre>
<P>
(Note: this is an example of how to use <tt>iterator_traits</tt>; it is not
an example of good code.  There are better ways of finding the last 
element in a range of <A href="BidirectionalIterator.html">bidirectional iterators</A>, or even
<A href="ForwardIterator.html">forward iterators</A>.)
<h3>Definition</h3>
Defined in the standard header <A href="iterator">iterator</A>, and in the
nonstandard backward-compatibility header <A href="iterator.h">iterator.h</A>.
<h3>Template parameters</h3>
<Table border>
<TR>
<TH>
Parameter
</TH>
<TH>
Description
</TH>
<TH>
Default
</TH>
</TR>
<TR>
<TD VAlign=top>
<tt>Iterator</tt>
</TD>
<TD VAlign=top>
The iterator type whose associated types are being accessed.
</TD>
<TD VAlign=top>
&nbsp;
</TD>
</tr>
</table>
<h3>Model of</h3>
<A href="DefaultConstructible.html">Default Constructible</A>, <A href="Assignable.html">Assignable</A>
<h3>Type requirements</h3>
<UL>
<LI>
<tt>Iterator</tt> is a model of one of the iterator concepts.
   (<A href="InputIterator.html">Input Iterator</A>, <A href="OutputIterator.html">Output Iterator</A>, <A href="ForwardIterator.html">Forward Iterator</A>,
    <A href="BidirectionalIterator.html">Bidirectional Iterator</A>, or <A href="RandomAccessIterator.html">Random Access Iterator</A>.)
</UL>
<h3>Public base classes</h3>
None.
<h3>Members</h3>
None, except for nested types.  
<Table border>
<TR>
<TH>
Member
</TH>
<TH>
Description
</TH>
</TR>
<TR>
<TD VAlign=top>
<tt>iterator_category</tt>
</TD>
<TD VAlign=top>
One of the types <tt>input_iterator_tag</tt>, <tt>output_iterator_tag</tt>,
   <tt>forward_iterator_tag</tt>, <tt>bidirectional_iterator_tag</tt>, or
   <tt>random_access_iterator_tag</tt>.  An iterator's category is the 
   <i>most specific</i> iterator concept that it is a model of.
</TD>
</TR>
<TR>
<TD VAlign=top>
<tt>value_type</tt>
</TD>
<TD VAlign=top>
<tt>Iterator</tt>'s value type, as defined in the <A href="trivial.html">Trivial Iterator</A>
   requirements.
</TD>
</TR>
<TR>
<TD VAlign=top>
<tt>difference_type</tt>
</TD>
<TD VAlign=top>
<tt>Iterator</tt>'s distance type, as defined in the <A href="InputIterator.html">Input Iterator</A>
   requirements.
</TD>
</TR>
<TR>
<TD VAlign=top>
<tt>pointer</tt>
</TD>
<TD VAlign=top>
<tt>Iterator</tt>'s pointer type: a pointer to its value type.
</TD>
</TR>
<TR>
<TD VAlign=top>
<tt>reference</tt>
</TD>
<TD VAlign=top>
<tt>Iterator</tt>'s reference type: a reference to its value type.
</TD>
</tr>
</table>
<h3>Notes</h3>
<P><A name="3">[3]</A>
The <tt>iterator_traits</tt> class relies on a C++ feature known as
<i>partial specialization</i>.  Many of today's compilers don't implement
the complete standard; in particular, many compilers do not support
partial specialization.  If your compiler does not support partial
specialization, then you will not be able to use
<tt>iterator_traits</tt>, and you will have to continue using the old
iterator tag functions <tt><A href="iterator_category.html">iterator_category</A></tt>, <tt><A href="distance_type.html">distance_type</A></tt>, and
<tt><A href="value_type.html">value_type</A></tt>.  This is one reason that those functions have not
yet been removed.
<h3>See also</h3>
The <A href="Iterators.html">iterator overview</A>,
<A href="iterator_tags.html">iterator tags</A>,
<tt><A href="input_iterator_tag.html">input_iterator_tag</A>,
</tt><A href="output_iterator_tag.html">output_iterator_tag</A>,
<tt><A href="forward_iterator_tag.html">forward_iterator_tag</A>,
</tt><A href="bidirectional_iterator_tag.html">bidirectional_iterator_tag</A>,
<tt><A href="random_access_iterator_tag.html">random_access_iterator_tag</A>,
</tt><A href="input_iterator.html">input_iterator</A>,
<tt><A href="output_iterator.html">output_iterator</A>,
</tt><A href="forward_iterator.html">forward_iterator</A>,
<tt><A href="bidirectional_iterator.html">bidirectional_iterator</A>,
</tt><A href="random_access_iterator.html">random_access_iterator</A>

<!--start footer--> 
